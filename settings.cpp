#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{
    this->close();
}

void settings::on_pushButtonSearch_clicked()
{
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    for(int i = 0; i < devices.count(); i++) {
      ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
    }
}

void settings::on_pushButtonConnect_clicked()
{
    emit wyborcom(ui->comboBoxDevices->currentText());
    qDebug() << "przekzano port";


}

void settings::on_pushButtonDisconnect_clicked()
{
    emit odlacz();
}
