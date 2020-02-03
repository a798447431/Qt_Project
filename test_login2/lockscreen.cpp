#include "lockscreen.h"
#include "ui_lockscreen.h"

lockscreen::lockscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lockscreen)
{
    ui->setupUi(this);
}

lockscreen::~lockscreen()
{
    delete ui;
}
