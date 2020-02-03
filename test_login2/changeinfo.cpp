#include "changeinfo.h"
#include "ui_changeinfo.h"
#include "singleton.h"
#include "cautomessagebox.h"

#include <QSqlQuery>
#include <QDebug>

changeinfo::changeinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeinfo)
{
    ui->setupUi(this);
    m_pTimer = new QTimer(this);
    m_pTimer->setSingleShot(true);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(get_user_info()));
}

changeinfo::~changeinfo()
{
    delete ui;
}

void changeinfo::get_user_info() {
    QString temp_info = QString("select * from info.userinfo where account_num='%1'").arg(SingleTon::GetInstance()->return_list_end());
    QSqlQuery query;
    query.exec(temp_info);
    if (query.first()) {
        QString changeinfo_account_num = query.value(0).toString();
        this->ui->le_changeinfo_account_num->setText(changeinfo_account_num);
        QString changeinfo_pwd = query.value(1).toString();
        this->ui->le_changeinfo_pwd->setText(changeinfo_pwd);
        QString changeinfo_systemrole = query.value(2).toString();
        if (changeinfo_systemrole == "教练员") {
            this->ui->cb_changeinfo_systemrole->setCurrentIndex(1);
        } else if (changeinfo_systemrole == "受训者") {
            this->ui->cb_changeinfo_systemrole->setCurrentIndex(2);
        } else if (changeinfo_systemrole == "系统管理员") {
            this->ui->cb_changeinfo_systemrole->setCurrentIndex(3);
        } else {
            this->ui->cb_changeinfo_systemrole->setCurrentIndex(0);
        }
        QString changeinfo_username = query.value(3).toString();
        this->ui->le_changeinfo_username->setText(changeinfo_username);
        QString changeinfo_usersex = query.value(4).toString();
        if (changeinfo_usersex == "男") {
            this->ui->cb_changeinfo_usersex->setCurrentIndex(1);
        } else if (changeinfo_usersex == "女"){
            this->ui->cb_changeinfo_usersex->setCurrentIndex(2);
        } else {
            this->ui->cb_changeinfo_usersex->setCurrentIndex(0);
        }
        QString changeinfo_organization = query.value(5).toString();
        this->ui->le_changeinfo_organization->setText(changeinfo_organization);
        QString changeinfo_organization_code = query.value(6).toString();
        this->ui->le_changeinfo_organization_code->setText(changeinfo_organization_code);
        QString changeinfo_duty = query.value(7).toString();
        this->ui->le_changeinfo_duty->setText(changeinfo_duty);
        QString changeinfo_duty_code = query.value(8).toString();
        this->ui->le_changeinfo_duty_code->setText(changeinfo_duty_code);
    }
}

void changeinfo::on_btn_changeinfo_cancle_clicked()
{
    clear_info();
    this->close();   
}

void changeinfo::start_timer()
{
    m_pTimer->start(10);
}

void changeinfo::clear_info() {
    this->ui->le_changeinfo_account_num->clear();
    this->ui->le_changeinfo_pwd->clear();
    this->ui->cb_changeinfo_systemrole->setCurrentIndex(0);
    this->ui->le_changeinfo_username->clear();
    this->ui->cb_changeinfo_usersex->setCurrentIndex(0);
    this->ui->le_changeinfo_organization->clear();
    this->ui->le_changeinfo_organization_code->clear();
    this->ui->le_changeinfo_duty->clear();
    this->ui->le_changeinfo_duty_code->clear();
    return ;
}

void changeinfo::on_btn_changeinfo_confirm_clicked()
{
    CAutoMessageBox msg;
    QString account_num = this->ui->le_changeinfo_account_num->text();
    QString pwd = this->ui->le_changeinfo_pwd->text();
    QString system_role = this->ui->cb_changeinfo_systemrole->currentText();
    QString username = this->ui->le_changeinfo_username->text();
    QString usersex = this->ui->cb_changeinfo_usersex->currentText();
    QString organization = this->ui->le_changeinfo_organization->text();
    QString organization_code = this->ui->le_changeinfo_organization_code->text();
    QString duty = this->ui->le_changeinfo_duty->text();
    QString duty_code = this->ui->le_changeinfo_duty_code->text();
    if (pwd == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("密码不能为空!"));
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
    else if (duty_code == ""){
        msg.AutoSetSize(400, 200);
        msg.setText(tr("职务代码不能为空"));
        msg.setWindowTitle(tr("警告"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    }
    else {
        QSqlQuery query;
        query.prepare("update info.userinfo set passwd=?,system_role=?,username=?,usersex=?,organization=?,organization_code=?,duty=?,duty_code=? where account_num=?");
        query.addBindValue(pwd);
        query.addBindValue(system_role);
        query.addBindValue(username);
        query.addBindValue(usersex);
        query.addBindValue(organization);
        query.addBindValue(organization_code);
        query.addBindValue(duty);
        query.addBindValue(duty_code);
        query.addBindValue(account_num);
        if (query.exec()) {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("修改成功！"));
            msg.setWindowTitle(tr("成功"));
            msg.setIcon(QMessageBox::Information);
            msg.addButton(tr("确定"),QMessageBox::AcceptRole);
            msg.exec();
            this->close();
        } else {
            msg.AutoSetSize(400, 200);
            msg.setText(tr("修改失败，请重试！"));
            msg.setWindowTitle(tr("错误"));
            msg.setIcon(QMessageBox::Critical);
            msg.addButton(tr("返回"),QMessageBox::RejectRole);
            msg.exec();
            this->close();
        }
    }
}
