/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月09日 星期一 14时58分41秒
 ************************************************************************/

#include <QApplication>
#include <QLabel> //标签

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //窗口
    QLabel *label = new QLabel("hello world!");
    label->resize(300, 250);
    label->show();
    return a.exec();
}

//qmake -project -> .pro
//qmake  -> makefile
//make -> 可执行程序
//a.exec 主运行循环
//动力 -> 事件 时间点 不确定
//不停监听
//
//QT实际要学习的东西 ： 
//1, 界面怎么写
//2, 怎样处理用户地点击或者其他事件
