#include "registe.h"
#include "ui_registe.h"
#include <QString>
#include "cautomessagebox.h"
#include <QSqlQuery>
#include <QDebug>

/*
 * 新建用户窗口
 * 1.获取QLine内用户输入的信息，将其保存到字符串中
 * 2.判断关键信息是否为空，若为空，弹出信息框提示用户
 * 3.判断数据表中是否已经有了该帐号信息，若有，弹出信息框提示用户
 * 4.若没有，则拼接sql语句
 * 5.调用exec()方法去执行sql语句，新建成功后退出窗口，不成功则弹出信息框提示用户
 * 6.清空用户输入信息，以便下次使用新建用户窗口
*/

registe::registe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registe)
{
    ui->setupUi(this);
}

registe::~registe()
{
    delete ui;
}

void registe::on_btn_registe_clicked() {
    CAutoMessageBox msg;
    QString account_num = this->ui->le_usernum->text();
    QString pwd = this->ui->le_pwd->text();
    QString sure_pwd = this->ui->le_surepwd->text();
    QString system_role = this->ui->cbb_system_role->currentText();
    QString username = this->ui->le_username->text();
    QString usersex = this->ui->cbb_usersex->currentText();
    QString organization = this->ui->le_organization->text();
    QString organization_code = this->ui->le_origanization_code->text();
    QString duty = this->ui->le_duty->text();
    QString duty_code = this->ui->le_duty_code->text();
    if (account_num == "") {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("帐号不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (pwd == "") {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("密码不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (sure_pwd == "") {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("请再次确认密码!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (pwd != sure_pwd) {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("两次密码输入不一致!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (username == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("姓名不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (organization == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("机构不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (organization_code == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("机构代码不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (duty == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("职务不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else if (duty_code == "") {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("职务代码不能为空!"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else {
        QString i = QString("insert into info.userinfo values ('%1','%2','%3','%4','%5','%6','%7','%8','%9');")
                .arg(account_num).arg(pwd).arg(system_role).arg(username).arg(usersex).arg(organization)
                .arg(organization_code).arg(duty).arg(duty_code);
        QString S = QString("select * from info.userinfo where account_num='%1' ").arg(account_num);
        QSqlQuery query;
        if (query.exec(i)) {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("帐号注册成功!"));
            msg.setWindowTitle(tr("成功"));
            msg.setIcon(QMessageBox::Information);
            msg.addButton(tr("确定"),QMessageBox::AcceptRole);
            msg.exec();
            clearUserInterface();
            this->close();
        }
        else if(query.exec(S)&&query.first()) {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("帐号已存在，请重试!"));
            msg.setWindowTitle(tr("警告"));
            msg.setIcon(QMessageBox::Warning);
            msg.addButton(tr("返回"),QMessageBox::RejectRole);
            msg.exec();
        }
        else {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("注册失败，请重试!"));
            msg.setWindowTitle(tr("警告"));
            msg.setIcon(QMessageBox::Warning);
            msg.addButton(tr("返回"),QMessageBox::RejectRole);
            msg.exec();
            clearUserInterface();
            this->close();
        }
    }
}

void registe::clearUserInterface() {
    this->ui->le_usernum->clear();
    this->ui->le_pwd->clear();
    this->ui->le_surepwd->clear();
    this->ui->cbb_system_role->setCurrentIndex(0);
    this->ui->le_username->clear();
    this->ui->cbb_usersex->setCurrentIndex(0);
    this->ui->le_organization->clear();
    this->ui->le_origanization_code->clear();
    this->ui->le_duty->clear();
    this->ui->le_duty_code->clear();
    this->ui->le_usernum->setFocus();
}

void registe::on_btn_register_exit_clicked() {
    this->close();
}
