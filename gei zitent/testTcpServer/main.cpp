#include "mainwindow.h"
#include "tcpserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    TcpServer w;
    w.show();

    return a.exec();
}
