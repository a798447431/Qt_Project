#include "loginwidow.h"
#include "ui_loginwidow.h"

loginwidow::loginwidow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwidow)
{
    ui->setupUi(this);
}

loginwidow::~loginwidow()
{
    delete ui;
}
