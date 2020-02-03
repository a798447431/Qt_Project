#include "lockscreen.h"
#include "ui_lockscreen.h"

//锁屏功能没有实现，现在只有一个窗口

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
