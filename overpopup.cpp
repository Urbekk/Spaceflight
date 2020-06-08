#include "overpopup.h"
#include "ui_overpopup.h"

Overpopup::Overpopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overpopup){
    ui->setupUi(this);
}

Overpopup::~Overpopup(){
    delete ui;
}

void Overpopup::on_pushButton_clicked(){
    this->close();
}
