#include "changepasswd.h"
#include "ui_changepasswd.h"
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include "singleton.h"
#include "cautomessagebox.h"

changepasswd::changepasswd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepasswd)
{
    ui->setupUi(this);
}

changepasswd::~changepasswd()
{
    delete ui;
}

void changepasswd::on_btn_changepwd_clicked()
{
    CAutoMessageBox msg;
    QString changepwd_account_num = SingleTon::GetInstance()->get_Nowinfo();
    QString changepwd_oldpwd = this->ui->le_changepwd_oldpwd->text();
    QString changepwd_newpwd = this->ui->le_changepwd_newpwd->text();
    QString changepwd_repwd = this->ui->le_changepwd_repwd->text();
    if (changepwd_oldpwd == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("旧密码输入不正确！"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (changepwd_newpwd == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("请输入新密码！"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (changepwd_repwd == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("请再次输入新密码!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (changepwd_newpwd != changepwd_repwd){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("两次输入密码不一致!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else {
        QSqlQuery query;
        QString sure_accountnum = QString("select * from info.userinfo where account_num='%1' and passwd='%2'").arg(changepwd_account_num).arg(changepwd_oldpwd);
        QString changepwd = QString("UPDATE info.userinfo SET passwd='%1' WHERE account_num='%2'").arg(changepwd_newpwd).arg(changepwd_account_num);
        if(query.exec(sure_accountnum) && query.first()) {
            if (query.exec(changepwd)) {
                msg.AutoSetSize(400, 200);
                msg.setText(tr("修改成功！"));
                msg.setWindowTitle(tr("成功"));
                msg.setIcon(QMessageBox::Information);
                msg.addButton(tr("确定"),QMessageBox::AcceptRole);
                msg.exec();
                clearChangePwdInterface();
                this->close();
            } else {
                msg.AutoSetSize(400, 200);
                msg.setText(tr("修改失败，请重试！"));
                msg.setWindowTitle(tr("错误"));
                msg.setIcon(QMessageBox::Critical);
                msg.addButton(tr("返回"),QMessageBox::RejectRole);
                msg.exec();
            }
        }
        else {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("原始密码错误，请重试！"));
            msg.setWindowTitle(tr("错误"));
            msg.setIcon(QMessageBox::Critical);
            msg.addButton(tr("返回"),QMessageBox::RejectRole);
            msg.exec();
            this->ui->le_changepwd_oldpwd->clear();
            clearChangePwdInterface();
        }
    }
}

void changepasswd::clearChangePwdInterface() {
    this->ui->le_changepwd_oldpwd->clear();
    this->ui->le_changepwd_newpwd->clear();
    this->ui->le_changepwd_repwd->clear();
    return ;
}

void changepasswd::on_btn_changepwd_exit_clicked() {
    this->close();
}
