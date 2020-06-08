#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QDateTime>
#include <QtSerialPort/QSerialPort>


namespace Ui {
class settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    //void on_pushButton_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();
signals:
    void setCom(QString string);
    void disconnect();
private:
    Ui::settings *ui;
    QSerialPort *device;
};

#endif // SETTINGS_H
