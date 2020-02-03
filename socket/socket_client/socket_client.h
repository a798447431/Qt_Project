#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
namespace Ui {
class socket_client;
}

class socket_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit socket_client(QWidget *parent = nullptr);
    ~socket_client();

private slots:
    void on_btn_bind_clicked();
    void doProcessConnect();
    void doProcessReadyRead();
    void doProcessDissconnect();
    void doProcessError(QAbstractSocket::SocketError);

    void on_btn_send_clicked();

private:
    Ui::socket_client *ui;
    QTcpSocket *myClient;

    void init();
};

#endif // SOCKET_CLIENT_H
