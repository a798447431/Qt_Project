#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QLineEdit>
#include <QString>
#include "cautomessagebox.h"
#include <QSqlQuery>
#include "registe.h"
#include "singleton.h"

loginwindow::loginwindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_btn_login_clicked() {
    CAutoMessageBox msg;
    QString account_number = this->ui->le_login_account_num->text();
    QString pwd = this->ui->le_login_passwd->text();
    if (account_number == "") {
        CAutoMessageBox msg;
        msg.AutoSetSize(400, 200);
        msg.setText(tr("用户名不能为空，请重新输入"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
    } else if(pwd == "") {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("密码不能为空，请重新输入"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
    } else {
        QString S = QString("select * from info.userinfo where account_num='%1' and passwd='%2' ").arg(account_number).arg(pwd);
        QSqlQuery query;
        query.exec(S);
        if (query.first()) {
            SingleTon::GetInstance()->set_Nowinfo(account_number);
            this->close();
            m.setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
            m.showFullScreen();
            m.show();
        } else {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("用户名或者密码错误，请重新输入"));
            msg.setWindowTitle(tr("错误"));
            msg.setIcon(QMessageBox::Critical);
            msg.addButton(tr("返回"),QMessageBox::AcceptRole);
            msg.exec();
        }
    }
}

void loginwindow::on_btn_exit_clicked()
{
    this->close();
}
