#include "overpopup.h"
#include "ui_overpopup.h"

overpopup::overpopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overpopup)
{
    ui->setupUi(this);
}

overpopup::~overpopup()
{
    delete ui;
}

void overpopup::on_pushButton_clicked()
{
    this->close();
}
