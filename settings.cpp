#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings){
    ui->setupUi(this);
    this->device = new QSerialPort(this);
}

Settings::~Settings(){
    delete ui;
}

/*void Settings::on_pushButton_clicked(){
    this->close();
}*/

void Settings::on_pushButtonSearch_clicked(){
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    for(int i = 0; i < devices.count(); i++) {
        ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
    }
}

void Settings::on_pushButtonConnect_clicked(){
    emit setCom(ui->comboBoxDevices->currentText());
    qDebug() << "przekzano port";
}

void Settings::on_pushButtonDisconnect_clicked(){
    emit disconnect();
}
