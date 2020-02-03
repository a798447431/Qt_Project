#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionaddStu_triggered()
{
   // addStu a;
   // a.show();
   // a.exec(); //模态视图
   // show对象不会被销毁
   this->a.show();
    // 1 exec() 确定型的
    // 2 show() 确认型的
}

void MainWindow::on_actionqueryStu_triggered()
{
    this->b.show();
}
