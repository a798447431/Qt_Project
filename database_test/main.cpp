#include "mainwindow.h"
#include "connection.h"
#include <QProcess>
#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    if (!createConnection()) return 1;
    return a.exec();
}
