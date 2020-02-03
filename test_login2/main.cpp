#include "loginwindow.h"

#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QTextCodec>
#include <QTime>
#include <QtDebug>
#include <QDesktopWidget>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Courier New", 14, QFont::Normal, false);
    QApplication::setFont(font);
    loginwindow w;
    database::connect_database();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    w.show();
    return a.exec();
}
