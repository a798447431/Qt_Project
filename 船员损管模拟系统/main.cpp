/*
 * 程序设计思路
 * 一.功能模块
 *      1. 登录模块，2.主界面模块，3.用户管理模块，4.数据库模块，5.临时信息存储模块，6.用户信息修改模块，7.登录者密码修改模块，8.新建用户模块
 *
 * 二.模块设计思路
 *      1.登录模块：
 *          登录模块分为用户信息输入和信息判断两部分
 *          首先判断用户是否输入了帐号和密码，若有没有输入的项，提示用户
 *          若帐号密码都输入，则判断数据库中是否存在该帐号信息，若不存在则提示用户
 *          若该帐号信息在数据库中存在，则判断在数据表中与该帐号对应的密码信息是否与用户输入的密码相同
 *          如果密码不相同，则提示用户，密码相同，则登录成功，跳转到主界面，跳转时将主界面设置为无边框全屏显示
 *          登录成功时将登录用户的帐号信息保存在临时信息存储模块，在主界面模块，用户管理模块，登录者密码修改模块都会调用该信息
 *
 *      2.主界面模块：
 *          由于主界面有部分功能没有实现，所以目前只有用户管理模块跳转和系统状态栏两部分
 *          点击用户管理按钮时关闭主界面，显示用户管理界面，跳转时将用户管理界面设置为无边框全屏显示，同时启动用户管理模块的计时器函数
 *          通过提取保存在临时信息存储模块的登录用户帐号信息在数据表中获取对应的姓名，系统角色信息
 *          将姓名，系统角色信息和系统时间显示在系统状态栏上，系统时间通过提取本地时间并用定时器设置每秒进行刷新显示实现
 *
 *      3.用户管理模块：
 *          用户管理模块主要分为信息查询，信息删除，信息修改，新建用户，修改密码四个部分
 *          首先在刚进入界面时要表格中显示当前数据表中的全部信息，因此在刚进入用户管理界面时就启动一个计时器，当计时器触发timeout信号时，调用显示全部信息的函数
 *          若用户进行搜索操作，判断用户是否输入了要查询的信息，若没有则提示用户，若有则根据输入的信息在数据表中进行查找，将查找到的所有信息显示在表格中
 *          若用户通过复选框勾选了多条信息，则将勾选的信息存入到临时信息存储模块，在信息修改和信息删除功能都有用到其存储的信息
 *          若用户进行信息修改操作，则先判断临时存储模块中是否只存储了一条信息，若没有或有多条信息则提示用户，否则跳转到用户信息修改界面
 *          若用户进行新建用户操作，则跳转到新建用户界面
 *          若用户进行删除操作，则先判断临时存储模块中存储了几条信息，若没有信息则提示用户，若有一条及以上的信息，则读取临时存储模块存储的全部帐号信息并在数据表中删除这些信息
 *          系统状态栏部分和主界面的相同
 *          当从用户管理模块返回主界面时，由于用户管理界面是主界面的子界面，没办法直接返回，因此通过发送信号，触发主界面的显示函数显示主界面并关闭当前界面
 *
 *      4.数据库模块：
 *          数据库模块提供了一个链接数据库的方法，可以在别的模块中导入数据库模块的头文件来使用该方法来链接数据库
 *
 *      5.临时信息存储模块：
 *          临时信息存储模块用来存储用户的登录帐号和要删除或进行修改的帐号信息，可以跨类使用，存储的信息全局唯一，每个类调用到的都是相同的信息
 *          存储的信息分为两种，一种是用户的登录帐号，用字符串进行存储，另一种是在用户管理模块中被复选框勾选的信息，用map数据结构进行存储
 *
 *      6.用户信息修改模块：
 *          用户信息修改模块分为修改信息，用户信息输入，信息判断和更新信息四部分
 *          首先将存入在临时信息存储模块的帐号信息读取出来，将数据表中的各项信息写在对应的界面位置上
 *          判断用户是否修改了各项信息，若有关键信息空白，提示用户
 *          若用户的关键信息都已经填写，则将修改后的信息更新到数据表中并退出当前界面，若更新出错则提示用户
 *
 *      7.登录者密码修改模块：
 *          登录者密码修改模块分为输入密码，确认密码，更新密码三部分
 *          首先将存入在临时信息存储模块的帐号信息读取出来，在数据表中提取出对应的密码信息
 *          判断用户是否有信息没有填写，如果有提示用户
 *          若信息都已经填写，则判断旧密码是否与数据表中的密码相同，若不同则提示用户
 *          判断两次输入的新密码是否相同，不同则提示用户
 *          将输入的新密码更新到数据表中并退出当前界面，若更新出错则提示用户
 *
 *      8.新建用户模块：
 *          新建用户模块分为用户信息填写和更新信息两部分
 *          首先判断用户是否有必要信息没有填写，有则提示用户
 *          若必要信息都填写，则将新信息更新到数据表中后退出当前界面，若更新出错则提示用户
 *
*/

#include "loginwindow.h" // 导入登录窗口的头文件
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget> //该类提供了对屏幕信息的访问
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
     * QFont用来设置字体
     * 第一项用来设置字体类型，我设置为黑体
     * 第二项用来设置字体大小
     * 第三项用来设置字体重量，正常设置为Normal
     * 第四项用来设置是否为斜体，true为开启斜体
    */
    QFont font("SimHei", 14, QFont::Normal, false);
    QApplication::setFont(font);
    loginwindow w; //生成登录窗口对象w
    database db;
    db.connect_database();
    /*
     * 将登录窗口通过move函数移动到屏幕中央
     * 通过屏幕和登录窗口的长宽计算出屏幕中心的位置
    */
    w.move((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    w.show(); //显示登录窗口
    return a.exec();
}
