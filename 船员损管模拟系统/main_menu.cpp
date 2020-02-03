#include "main_menu.h"
#include "ui_main_menu.h"
#include "singleton.h"
#include "cautomessagebox.h"
#include <QDateTime> //QDataTime用来读取当前日期时间

main_menu::main_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this); //QTimer类提供了重复和单次触发信号的定时器。
    connect(timer, SIGNAL(timeout()), this, SLOT(main_init_system_state()));//链接信号与槽函数，当定时器停止时，执行系统状态栏函数
    connect(&mm, SIGNAL(SignFather()), this, SLOT(return_main_menu())); //该信号与槽函数使用户信息管理窗口可以返回到系统主窗口
    timer->start(1000);//设置短时间定时器，使得刚进入系统主窗口时就触发信号，执行系统状态栏函数并更新时间信息
}

main_menu::~main_menu()
{
    delete ui;
}

/*
 * 主窗口部分由于时间原因有许多功能没有实现
 * 没有实现的部分有帮助，锁屏和修改用户密码
 * 实现功能有跳转到信息管理窗口，最小化，，退出和系统状态栏
*/

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
    QWidget::showMinimized(); //设置窗口最小化
    return ;
}

/*
void main_menu::on_btn_mainmenu_changpwd_clicked()
{
    this->cp.show();
}
*/

void main_menu::on_btn_mainmenu_exit_clicked() //退出按钮，信息框提示是否退出
{
    CAutoMessageBox msg;
    msg.AutoSetSize(400, 200);
    msg.setText(tr("确定要退出船舶**模拟训练系统吗?"));
    msg.setWindowTitle(tr("退出"));
    msg.setIcon(QMessageBox::Question);
    msg.addButton(tr("确定"),QMessageBox::AcceptRole);
    msg.addButton(tr("返回"),QMessageBox::RejectRole);
    if(msg.exec() == QMessageBox::AcceptRole) { //根据信息框按钮处理是否退出
        mm.close();
        this->close();
    } else {
        return ;
    }
}

void main_menu::on_btn_userinfo_manage_clicked() //进入用户信息管理窗口
{
    this->close();//关闭系统主窗口
    mm.setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    mm.showFullScreen();
    mm.start_timer(); //触发用户信息管理窗口的定时器
    mm.show();
}

void main_menu::main_init_system_state() { //系统状态栏，用定时器触发，显示登录者姓名，系统角色，时间等信息
    /*
     * 1.先读取单例模式中保存的登录者的帐号信息
     * 2.用读取的帐号信息拼接sql语句并查找
     * 3.读取登录帐号的姓名和系统角色信息
     * 4.将姓名和系统角色信息显示在QLable上
    */
    QString temp_info = QString("select * from info.userinfo where account_num='%1'").arg(SingleTon::GetInstance()->get_Nowinfo());
    QString tmp_info_systemrole = nullptr;
    QString tmp_info_username = nullptr;
    QSqlQuery query;
    query.exec(temp_info);
    if (query.first()) {
        //用QSqlQuery的value方法提取登录帐号的姓名和系统角色信息
        tmp_info_systemrole = query.value(2).toString();
        tmp_info_username = query.value(3).toString();
    }
    //将保存的信息显示在QLable上
    this->ui->lb_mainmenu_system_username->setText(QString("当前登录者：%1").arg(tmp_info_username));
    this->ui->lb_mainmenu_system_role->setText(QString("系统角色：%1").arg(tmp_info_systemrole));
    this->ui->lb_mainmenu_system_state->setText(QString("当前系统状态：无"));
    main_timerUpdate();//显示当前系统时间信息
    return ;
}

void main_menu::main_timerUpdate() {
    //系统时间通过每秒触发的定时器更新
    QDateTime time = QDateTime::currentDateTime(); //QDateTime获取当前系统时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd"); //将时间信息转化为字符串
    this->ui->lb_mainmenu_system_time->setText(str); //显示在QLable上
    return ;
}

void main_menu::return_main_menu() { //从信息管理窗口返回当前窗口
    mm.close();
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    this->showFullScreen();
    this->show();
}
