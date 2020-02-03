#include "socket_server.h"
#include "ui_socket_server.h"
#include <QDebug>
#include <QString>
#define MAXCNT 10
socket_server::socket_server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::socket_server)
{
    ui->setupUi(this);
    Init();
}

socket_server::~socket_server()
{
    delete ui;
}

void socket_server::on_btn_bind_clicked()
{   QString myAddr;
    //自动获取ｉｐ地址
 //  QList<QHostAddress> addrs = QNetworkInterface::allAddresses();
//    for (int i = 0; i < addrs.length(); i++) {
//        QHostAddress addr = addrs.at(i);
//        qDebug() << addr.toString();
//        if (addr.toString().contains("192.")) {
//            myAddr = addr.toString();
//            break;
//        }
//    }

    //手动获取ｉｐ
    myAddr = this->ui->le_server_ip->text();


    QString myPort;
    myPort = this->ui->le_server_port->text();
    QString msg;
    bool ret = myserver->listen(QHostAddress(myAddr),myPort.toUInt());
    if (!ret) {
        this->ui->te_server->append("绑定失败");

    } else {
        this->ui->te_server->append(("绑定成功"));
        this->ui->btn_bind->setEnabled(false);
    }
    myserver->setMaxPendingConnections(MAXCNT);
    connect(myserver, SIGNAL(newConnection()),this,SLOT(doprocessNewConnection()));
    connect(myserver, SIGNAL(acceptError(QAbstractSocket::SocketError)),this, SLOT(doproccessAcceptError(QAbstractSocket::SocketError)));

}

void socket_server::Init() {
    myserver = new QTcpServer(this);
}
void socket_server::doprocessNewConnection(){
    client = myserver->nextPendingConnection();
    arrClient.append(client);
    QString msg = QString("客户端[%1:%2] 连入！")
            .arg(client->peerAddress().toString())
            .arg(client->peerPort());
    this->ui->te_server->append(msg);
    //客户端断开
    connect(client, SIGNAL(disconnected()),this, SLOT(doDisconnect()));
    //读取客户端内容
    connect(client, SIGNAL(readyRead()), this, SLOT(doReadyRead()));
    //客户端连入
   // connect(client, SIGNAL(connected()), this, SLOT(doConnect()));
}
void socket_server:: doprocessAcceptError(QAbstractSocket::SocketError err) {
    qDebug() << err;
}

void socket_server::doDisconnect(){
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString msg = QString("客户：[%1 : %2] 退出！").arg(client->peerAddress().toString())
            .arg(client->peerPort());
    this->ui->te_server->append(msg);
    //删除客户端
    for (int i = 0; i <arrClient.length(); i++) {
        if (arrClient.at(i)->peerAddress() == client->peerAddress()) {
            if (arrClient.at(i)->peerPort() == client->peerPort()) {
                arrClient.removeAt(i);
                break;
            }
        }
    }
}

void socket_server:: doReadyRead(){
    QTcpSocket *client = (QTcpSocket *)this->sender();

    QString str1 = QString("客户端[%1 : %2] 说：")
            .arg(client->peerAddress().toString())
            .arg(client->peerPort());
    QString msg;
    QString str2;
    while(!client->atEnd()) {
        msg.append(QString(client->readAll()));
    }
     str2 = QString("%1%2").arg(str1).arg(msg);
     this->ui->te_server->append(str2);
}



void socket_server::on_btn_send_clicked()
{
    QString ip = this->ui->le_client_ip->text();
    QString port = this->ui->le_client_port->text();
    for (int i = 0; i < arrClient.length(); i++) {
        if (arrClient.at(i)->peerAddress().toString() == ip) {
            if (arrClient.at(i)->peerPort() == port.toUInt()) {
                QString msg = this->ui->te_client->toPlainText();
                arrClient.at(i)->write(msg.toUtf8());
                this->ui->te_client->clear();
                break;
            }
        }
    }
}



