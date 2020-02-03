#include "socket_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    socket_client w;
    w.show();

    return a.exec();
}
