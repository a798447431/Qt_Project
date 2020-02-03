#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QTcpSocket>
#include <QIODevice>
#include <QList>
namespace Ui {
class socket_server;
}

class socket_server : public QMainWindow
{
    Q_OBJECT

public:
    explicit socket_server(QWidget *parent = nullptr);
    ~socket_server();

private slots:
    void on_btn_bind_clicked();
    void doprocessNewConnection();
    void doprocessAcceptError(QAbstractSocket::SocketError);
    void doDisconnect();
    void doReadyRead();
   // void doConnect();
    void on_btn_send_clicked();

private:
    Ui::socket_server *ui;
    QTcpServer *myserver;
    void Init();
    QList<QTcpSocket *> arrClient;
     QTcpSocket *client;
};

#endif // SOCKET_SERVER_H
