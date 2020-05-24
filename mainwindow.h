#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <player.h>
#include <QGraphicsView>
#include <QObject>
#include <QVector>
#include <asteroid.h>
#include <fuel.h>
#include <settings.h>
#include <overpopup.h>
#include <crashpopup.h>
#include <graphs.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void gameInit();
    void repeatableParameters();
signals:
    void freeze();
    void resume();
    void sendPast(QVector<QVector<int>>);
    void sendNow(QVector<int>);
private slots:
    void spawnA();
    void spawnF();
    void countpoints();
    void stoptimers();
    void collectFuel();
    void gameover();
    void connection(QString string);
    void readFromPort();
    //void clearData();
    void on_pushButtonNewGame_clicked();
    void on_pushButtonPause_toggled(bool checked);
    void on_pushButtonSettings_clicked();
    void on_pushButtonGraph_clicked();
private:
    Ui::MainWindow *ui;
    QSerialPort *device;
    overpopup *oknoF;
    settings *oknoU;
    crashpopup *oknoC;
    graphs *oknoW;
    QGraphicsScene * scene;
    Player * player;
    QTimer * timer;
    QTimer * timerpoints;
    QTimer * timerfuel;
    QTimer * timerclear;
    Fuel * fuel;
    Asteroid * asteroid;
    int points;
    int gas;
    int flaga = 0;
    int drawing = 0;
    QVector <QVector<int>> pastdata;
};
#endif // MAINWINDOW_H
