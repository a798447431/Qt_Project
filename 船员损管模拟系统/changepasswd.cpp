#include "changepasswd.h"
#include "ui_changepasswd.h"
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include "singleton.h"
#include "cautomessagebox.h"

//修改当前系统登录用户的密码

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

void changepasswd::on_btn_changepwd_clicked() { //修改密码
    /*
     * 1.通过在登录窗口获取到的保存在单例模式中的用户帐号信息来进行密码修改
     * 2.判断用户的旧密码是否与数据表中的密码相同，不相同弹出信息框提示用户
     * 3.判断用户两次输入的新密码是否相同，不相同弹出信息框提示用户
     * 4.判断用户是否有未填入的信息，若有则弹出信息框提示用户
     * 5.将新密码更新到数据表对应的条目中并退出，若失败则弹出信息框提示
    */
    CAutoMessageBox msg;
    QString changepwd_account_num = SingleTon::GetInstance()->get_Nowinfo(); //获取用户帐号信息
    QString changepwd_oldpwd = this->ui->le_changepwd_oldpwd->text(); //获取用户输入信息
    QString changepwd_newpwd = this->ui->le_changepwd_newpwd->text();
    QString changepwd_repwd = this->ui->le_changepwd_repwd->text();

    //判断信息是否全部填入
    if (changepwd_oldpwd == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("旧密码未输入！"));
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
    else if (changepwd_newpwd != changepwd_repwd){ //判断两次输入密码是否一致
        msg.AutoSetSize(400, 200);
        msg.setText(tr("两次输入密码不一致!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else { //信息填入正确
        QSqlQuery query;
        QString sure_accountnum = QString("select * from info.userinfo where account_num='%1' and passwd='%2'").arg(changepwd_account_num).arg(changepwd_oldpwd);
        QString changepwd = QString("UPDATE info.userinfo SET passwd='%1' WHERE account_num='%2'").arg(changepwd_newpwd).arg(changepwd_account_num);
        if(query.exec(sure_accountnum) && query.first()) { //判断旧密码是否输入正确，正确则进行密码更新
            if (query.exec(changepwd)) { //更新用户密码
                msg.AutoSetSize(400, 200);
                msg.setText(tr("修改成功！"));
                msg.setWindowTitle(tr("成功"));
                msg.setIcon(QMessageBox::Information);
                msg.addButton(tr("确定"),QMessageBox::AcceptRole);
                msg.exec();
                clearChangePwdInterface(); //清空窗口信息
                this->close();
            } else { //更新失败则报错
                msg.AutoSetSize(400, 200);
                msg.setText(tr("修改失败，请重试！"));
                msg.setWindowTitle(tr("错误"));
                msg.setIcon(QMessageBox::Critical);
                msg.addButton(tr("返回"),QMessageBox::RejectRole);
                msg.exec();
            }
        }
        else { //旧密码不正确则清空窗口信息，弹出信息框提示用户
            msg.AutoSetSize(400, 200);
            msg.setText(tr("旧密码错误，请重试！"));
            msg.setWindowTitle(tr("错误"));
            msg.setIcon(QMessageBox::Critical);
            msg.addButton(tr("返回"),QMessageBox::RejectRole);
            msg.exec();
            this->ui->le_changepwd_oldpwd->clear();
            clearChangePwdInterface();
        }
    }
}

void changepasswd::clearChangePwdInterface() { //清空窗口信息方法
    this->ui->le_changepwd_oldpwd->clear();
    this->ui->le_changepwd_newpwd->clear();
    this->ui->le_changepwd_repwd->clear();
    return ;
}

void changepasswd::on_btn_changepwd_exit_clicked() { //退出窗口
    this->close();
}
