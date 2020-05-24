#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand( time( NULL ) );
    ui->setupUi(this);
    ui->pushButtonPause->setCheckable(true);
    this->device = new QSerialPort(this);
    gameInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* * * * * * * GAME SETTINGS * * * * * * * * */
void MainWindow::gameInit(){
    oknoU = new settings();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->setFixedSize(805,605);
    scene->setBackgroundBrush(QBrush(QImage(":/images/map.jpg")));
    scene->setSceneRect(0,0,800,600);
    timer = new QTimer(this);
    timerpoints = new QTimer(this);
    timerfuel = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawnA()));
    connect(timerpoints,SIGNAL(timeout()),this,SLOT(countpoints()));
    connect(timerfuel,SIGNAL(timeout()),this,SLOT(spawnF()));
    repeatableParameters();
}

/* * * * * * * GAME PARA * * * * * * * * */
void MainWindow::repeatableParameters(){
    player = new Player();
    player->setPixmap(QPixmap(":/images/spaceship.png"));
    scene->addItem(player);
    player->setPos(350,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    connect(player,SIGNAL(crash()),this,SLOT(gameover()));
    connect(player,SIGNAL(crash()),this,SLOT(stoptimers()));
    points = 0;
    gas = 20;//20
    timer->start(2000);//2000
    timerfuel->start(8000);//8000
    timerpoints->start(1000);

    //pastdata.clear();

}

/* * * * * * * NEW GAME * * * * * * * * */
void MainWindow::on_pushButtonNewGame_clicked()
{
    scene->clear();
    repeatableParameters();
    ui->progressBar->setValue(gas);
    flaga=0;
}

void MainWindow::spawnA()
{
    asteroid = new Asteroid(30+rand()%50,40);
    scene->addItem(asteroid);
    connect(this,SIGNAL(freeze()),asteroid,SLOT(stopmove()));
    connect(this,SIGNAL(resume()),asteroid,SLOT(startmove()));
}

void MainWindow::spawnF()
{
    fuel = new Fuel(30,40);
    scene->addItem(fuel);
    connect(fuel,SIGNAL(collect()),this,SLOT(collectFuel()));
    connect(this,SIGNAL(freeze()),fuel,SLOT(stopmove()));
    connect(this,SIGNAL(resume()),fuel,SLOT(startmove()));
}

void MainWindow::collectFuel()
{
    if(gas>85) gas = 85;
    gas=gas+15;
    ui->progressBar->setValue(gas);
}

void MainWindow::countpoints(){
    ui->lcdNumber->display(points++);
    ui->progressBar->setValue(gas--);
    if (gas==0){
        scene->clear();
    }
}

void MainWindow::stoptimers(){
    timer->stop();
    timerpoints->stop();
    timerfuel->stop();
    flaga=1;
}

void MainWindow::gameover(){
    if (gas > 0){
    oknoC = new crashpopup();
    oknoC->show();
    }
    else {
    oknoF = new overpopup();
    oknoF->show();
    }
}

void MainWindow::connection(QString string)
{
    QStringList portList = string.split("\t");
    qDebug() << portList;
    QString portName = portList.first();
    qDebug() << portName;
    this->device->setPortName(portName);
    if(device->open(QSerialPort::ReadWrite)) {
    this->device->setBaudRate(QSerialPort::Baud9600);
    this->device->setDataBits(QSerialPort::Data8);
    this->device->setParity(QSerialPort::NoParity);
    this->device->setStopBits(QSerialPort::OneStop);
    this->device->setFlowControl(QSerialPort::NoFlowControl);
    connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));
    }
}

void MainWindow::readFromPort() {
    /*********** RAMKA:  X xacc yacc zacc crc Z *************/
    QVector <int> dataMCU(3);
    uint sum;
    while(this->device->canReadLine()) {
        sum = 0;
        QString line = this->device->readLine();
        QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        for(int i = 0; i < 3; i++){
            dataMCU[i]=list.at(i+1).toInt();
            sum += dataMCU[i];
        }
        if((sum%128) == list.at(4).toInt()){
            if (flaga==0)
                player->moveACC(dataMCU[0],dataMCU[1],dataMCU[2]);
            pastdata.append(dataMCU);
            if (drawing == 1){
                emit sendNow(dataMCU);
            }
        }
    }
}

/*void MainWindow::clearData(){
    pastdata.clear();
    qDebug() << pastdata.size() << "porzadek";
    drawing = 0;
}*/

void MainWindow::on_pushButtonGraph_clicked()
{
    oknoW = new graphs(pastdata);
    oknoW -> show();
    drawing = 1;
    connect(this,SIGNAL(sendNow(QVector<int>)),oknoW,SLOT(newData(QVector<int>)));
    //connect(oknoW,SIGNAL(clearD()),this,SLOT(clearData()));
}

void MainWindow::on_pushButtonSettings_clicked()
{
    oknoU->show();
    connect(oknoU,SIGNAL(wyborcom(QString)),this,SLOT(connection(QString)));
}

void MainWindow::on_pushButtonPause_toggled(bool checked)
{
    if (checked){
        flaga = 1;
    emit freeze();
    timer->stop();
    timerpoints->stop();
    timerfuel->stop();
    }
    else{
        flaga = 0;
        emit resume();
        timerpoints->start(1000);
        timer->start(2000);
        timerfuel->start(8000);
    }

}
