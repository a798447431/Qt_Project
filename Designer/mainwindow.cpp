#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(谁，发出了什么信号，谁，执行什么操作）;
    connect(this->ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(login()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login() {
    static int count = 0;
    QString name = this->ui->le_account->text();
    QString passwd = this->ui->le_passwd->text();
    if (name == "jack" && passwd == "1234") {
        qDebug() << "登录成功";
    } else {
        qDebug() << "登录失败";
        count++;
        if (count >= 3) {
            //断开信号与槽链接
            disconnect(this->ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(login()));
        }
    }
}

//有什么控件 这些控件可以发出什么信号
//信号与槽机制
//槽函数

//搭建界面
//添加功能
  //链接信号与槽
    //链接

// 自动根据命名方式生成connect
void MainWindow::on_btnCancel_clicked() {
    this->close();
}

void MainWindow::on_le_account_textChanged(const QString &arg) {
    qDebug() << "文本改变了";
}
