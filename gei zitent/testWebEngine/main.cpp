#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainform.h"
#include "myform.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyForm w ;//创建主界面对象
    w.show();//显示主界面

    return app.exec();
}
