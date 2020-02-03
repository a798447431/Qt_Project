#include "tcpserver.h"
#include "ui_tcpserver.h"


TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    port = 8888;

}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::on_pushButtonCreateChattingRoom_clicked()
{
    server  = new Server(this, port);
    //处理updateserver信号，让界面更新信息
    connect(server, &Server::updateserver, this, &TcpServer::slotupdateserver);
    //button  set Enabled = false
    ui->pushButtonCreateChattingRoom->setEnabled(false);
}

void TcpServer::slotupdateserver(QString msg, int length)
{
    ui->textEdit->append(msg);
}
