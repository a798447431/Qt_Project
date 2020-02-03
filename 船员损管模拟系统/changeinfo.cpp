#include "changeinfo.h"
#include "ui_changeinfo.h"
#include "singleton.h"
#include "cautomessagebox.h"
#include <QSqlQuery>
#include <QDebug>

//该类用来显示修改用户信息窗口

changeinfo::changeinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeinfo)
{
    ui->setupUi(this);
    m_pTimer = new QTimer(this);
    m_pTimer->setSingleShot(true);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(get_user_info())); //定时器计时结束后发送timeout()信号，执行槽函数get_user_info()来获取被选择条目的用户信息
}

changeinfo::~changeinfo()
{
    delete ui;
}

void changeinfo::get_user_info() {
    //通过读取在用户信息管理窗口获取并存储在单例模式中map内的用户帐号信息来进行用户信息提取
    QString temp_info = QString("select * from info.userinfo where account_num='%1'").arg(SingleTon::GetInstance()->return_map_info().at(0));
    QSqlQuery query;
    query.exec(temp_info);
    if (query.first()) {  //如果该帐号存在，提取用户帐号在数据库中的其它信息并写到对应的QLine和QComboBox中
        QString changeinfo_account_num = query.value(0).toString(); //用QSqlQuery的value方法进行信息提取，用toString方法将信息转化为字符串
        this->ui->le_changeinfo_account_num->setText(changeinfo_account_num);//用QLine的setText()方法将字符串写入到QLine上显示，下同
        QString changeinfo_pwd = query.value(1).toString();
        this->ui->le_changeinfo_pwd->setText(changeinfo_pwd);
        QString changeinfo_systemrole = query.value(2).toString(); //QComboBox的设置需要对字符串进行判断，依据提取出来的信息进行设置
        if (changeinfo_systemrole == "教练员") {
            this->ui->cb_changeinfo_systemrole->setCurrentIndex(1); //使用QComboBox的setCurrentIndex()方法设置QCombox的显示内容，下同
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

void changeinfo::on_btn_changeinfo_cancle_clicked() {//退出窗口时将QLine和QComboBox的全部信息清空
    clear_info(); //清空全部信息
    this->close();   
}

void changeinfo::start_timer() {
    m_pTimer->start(100);
}

void changeinfo::clear_info() { //清空信息函数
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

void changeinfo::on_btn_changeinfo_confirm_clicked() {//修改用户信息并提交
    /*
     * 1.获取QLine内用户输入的信息，将其保存到字符串中
     * 2.判断关键信息是否为空，若为空，弹出信息框提示用户
     * 3.若关键信息全部填写，则调用QSqlQuery类的prepare()方法进行函数准备，准备给数据库的更新操作传值
     * 4.使用QSqlQuery类的addBindValue(value)方法按照prepare()内的item顺序来绑定值，简单来说就是根据sql语句内？的先后顺序进行赋值
     * 5.调用exec()方法去执行sql语句，修改成功后退出窗口，不成功则弹出信息框提示用户
    */
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
    if (pwd == ""){ //对关键信息是否填写进行判断
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
    else { //若关键信息全部填写，则将其修改写入数据表中
        QSqlQuery query;
        query.prepare("update info.userinfo set passwd=?,system_role=?,username=?,usersex=?,organization=?,organization_code=?,duty=?,duty_code=? where account_num=?");
        //prepare()是准备指令，准备给要执行的sql语句进行传值
        query.addBindValue(pwd); //绑定指令，把prepare（）中用？表示的量替换成相对应的数值量（int，float, QString等），替换是是按照？出现顺序替换的
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
