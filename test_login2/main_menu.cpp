#include "main_menu.h"
#include "ui_main_menu.h"
#include "singleton.h"
#include "cautomessagebox.h"
#include <QDateTime>

main_menu::main_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(main_init_system_state()));
    connect(&mm, SIGNAL(SignFather()), this, SLOT(return_main_menu()));
    timer->start(1000);
}

main_menu::~main_menu()
{
    delete ui;
}

void main_menu::on_btn_mainmenu_help_clicked()
{

}

/*
void main_menu::on_btn_mainmenu_lockscreen_clicked()
{
    this->ls.exec();
}
*/

void main_menu::on_btn_mainmenu_minimize_clicked()
{
    QWidget::showMinimized();
    return ;
}

/*
void main_menu::on_btn_mainmenu_changpwd_clicked()
{
    this->cp.show();
}
*/

void main_menu::on_btn_mainmenu_exit_clicked()
{
    CAutoMessageBox msg;
    msg.AutoSetSize(400, 200);
    msg.setText(tr("确定要退出船舶**模拟训练系统吗?"));
    msg.setWindowTitle(tr("退出"));
    msg.setIcon(QMessageBox::Question);
    msg.addButton(tr("确定"),QMessageBox::AcceptRole);
    msg.addButton(tr("返回"),QMessageBox::RejectRole);
    if(msg.exec() == QMessageBox::AcceptRole) {
        mm.close();
        this->close();
    } else {
        return ;
    }
}

void main_menu::on_btn_userinfo_manage_clicked()
{
    this->close();
    mm.setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    mm.showFullScreen();
    mm.start_timer();
    mm.show();
}

void main_menu::main_init_system_state() {
    QString temp_info = QString("select * from info.userinfo where account_num='%1'").arg(SingleTon::GetInstance()->get_Nowinfo());
    QString tmp_info_systemrole = nullptr;
    QString tmp_info_username = nullptr;
    QSqlQuery query;
    query.exec(temp_info);
    if (query.first()) {
        tmp_info_systemrole = query.value(2).toString();
        tmp_info_username = query.value(3).toString();
    }
    this->ui->lb_mainmenu_system_username->setText(QString("当前登录者：%1").arg(tmp_info_username));
    this->ui->lb_mainmenu_system_role->setText(QString("系统角色：%1").arg(tmp_info_systemrole));
    this->ui->lb_mainmenu_system_state->setText(QString("当前系统状态：无"));
    main_timerUpdate();
    return ;
}

void main_menu::main_timerUpdate() {
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    this->ui->lb_mainmenu_system_time->setText(str);
    return ;
}

void main_menu::return_main_menu() {
    mm.close();
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    this->showFullScreen();
    this->show();
}
