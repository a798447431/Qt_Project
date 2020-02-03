#include "socket_client.h"
#include "ui_socket_client.h"

socket_client::socket_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::socket_client)
{
    ui->setupUi(this);
    init();
}

socket_client::~socket_client()
{
    delete ui;
}


//func
void socket_client::init(){
    myClient = new QTcpSocket(this);
}
//endfunc

//slots
void socket_client::on_btn_bind_clicked()
{
    QString servIP = this->ui->le_server_ip->text();
    QString servPort= this->ui->le_server_port->text();
    myClient->connectToHost(QHostAddress(servIP),servPort.toUInt());

    connect(myClient,SIGNAL(connected()),this,SLOT(doProcessConnect()));
    connect(myClient,SIGNAL(readyRead()), this, SLOT(doProcessReadyRead()));
    connect(myClient, SIGNAL(disconnected()),this, SLOT(doProcessDissconnect()));
    connect(myClient, SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(doProcessError(QAbstractSocket::SocketError)));
}
void socket_client::doProcessConnect(){
    //qDebug() << "789456789456";
    QString msg = QString("链接成功");

    this->ui->te_server->append(msg);
    this->ui->btn_bind->setEnabled(false);
}

void socket_client::doProcessReadyRead(){
    QString msg, str1, str2;
    str1 = QString("服务器[%1:%2] 说:")
            .arg(myClient->peerAddress().toString())
            .arg(myClient->peerPort());
    while(!myClient->atEnd()) {
        str2.append(QString(myClient->readAll()));
    }
    msg = QString("%1%2").arg(str1).arg(str2);
    ui->te_server->append(msg);
}

void socket_client::doProcessDissconnect(){
    QString msg = "服务器退出";
    ui->te_server->append(msg);
    this->ui->btn_bind->setEnabled(true);
}
void socket_client::doProcessError(QAbstractSocket::SocketError err) {
    qDebug() << err;
}


void socket_client::on_btn_send_clicked()
{
    QString msg = this->ui->te_client->toPlainText();
    int ret = myClient->write(msg.toUtf8());
    if (ret < 0)
        return;
    this->ui->te_client->clear();

}




//end slots
