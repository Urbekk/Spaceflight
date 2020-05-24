#include "crashpopup.h"
#include "ui_crashpopup.h"

crashpopup::crashpopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crashpopup)
{
    ui->setupUi(this);
}

crashpopup::~crashpopup()
{
    delete ui;
}

void crashpopup::on_pushButton_clicked()
{
    this->close();
}
