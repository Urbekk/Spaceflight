#include "crashpopup.h"
#include "ui_crashpopup.h"

Crashpopup::Crashpopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crashpopup){
    ui->setupUi(this);
}

Crashpopup::~Crashpopup(){
    delete ui;
}

void Crashpopup::on_pushButton_clicked(){
    this->close();
}
