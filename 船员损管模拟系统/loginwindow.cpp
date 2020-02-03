#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QLineEdit>
#include <QString>
#include "cautomessagebox.h"
#include <QSqlQuery>
#include "registe.h"
#include "singleton.h" //引入单例模式头文件，单例模式存储了用户的帐号信息，并且可被任何其他类获取

loginwindow::loginwindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
}

loginwindow::~loginwindow() {
    delete ui;
}

void loginwindow::on_btn_login_clicked() {
    CAutoMessageBox msg; //生成自定义QMessage对象
    /*
     * 利用QLine的text()方法获取用户输入信息
     * account_num为用户帐号
     * pwd为用户密码，QLine中设置成了密码模式
    */

    QString account_number = this->ui->le_login_account_num->text();
    QString pwd = this->ui->le_login_passwd->text();

    /*
     * 登录功能实现部分
     * 1.对用户输入信息进行判断
     * 2.首先判断用户是否输入了帐号和密码，如果有帐号或者密码没有输入，则弹出信息框提示
     * 3.如果用户输入了全部信息，则将输入的信息与sql语句进行拼接
     * 4.通过QSqlQuery的exec()方法提交拼接好的sql语句
     * 5.判断数据库中是否拥有符合信息的条目，有则直接跳转到系统主界面，没有则弹出信息框提示
    */
    if (account_number == nullptr) { //判断帐号信息是否为空
        msg.AutoSetSize(400, 200); //设置信息框的长宽
        msg.setText(tr("用户名不能为空，请重新输入")); //设置信息框显示信息,tr()内部为显示的文字内容
        msg.setWindowTitle(tr("错误")); //设置信息框标题
        msg.setIcon(QMessageBox::Critical); //显示信息框图标，critical为错误图标，warning为警告图标，question为问号图标
        msg.addButton(tr("返回"),QMessageBox::AcceptRole); //设置信息框按钮,按钮角色有AcceptRole，YesRole，RejectRole等
        msg.exec(); //QMessageBox的显示有两个函数show()和exec()
        /*
         * show():
         *  显示一个非模式对话框。控制权即刻返回给调用函数。弹出窗口是否模式对话框，取决于modal属性的值。
         * exec():
         *  显示一个模式对话框，并且锁住程序直到用户关闭该对话框为止。
         *  在对话框弹出期间，用户不可以切换同程序下的其它窗口，直到该对话框被关闭。
        */

    } else if(pwd == nullptr) {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("密码不能为空，请重新输入"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
    } else {
        /*
         * 通过输入的帐号密码信息拼接sql语句并保存在字符串S中
        */
        QString S = QString("select * from info.userinfo where account_num='%1' and passwd='%2' ").arg(account_number).arg(pwd);
        QSqlQuery query;// QSqlQuery类提供了一种执行和操作SQL语句的方法, 因此添加了一个QSqlQuery对象
        query.exec(S); // 执行sql语句，返回执行结果
        if (query.first()) { //QSqlQuery类中当执行exec()后会把指针放在记录集中第一个记录之上，用first()方法来查看数据库中寻找到的第一条是否为符合的条目，有则直接登录
            SingleTon::GetInstance()->set_Nowinfo(account_number);//如果数据库中有该用户的信息，将其帐号信息存储到单例模式中
            this->close();//关闭登录窗口
            m.setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);//设置主窗口无边框
            m.showFullScreen();//设置主窗口全屏显示
            m.show();//显示主窗口
        } else { //若sql中没有该帐号信息，弹出信息框提示
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
    this->close(); //点击退出按钮后直接关闭登录窗口
}
