//用来监听的类Server
#include "server.h"
#include <QHostAddress>

Server::Server(QObject *parent, int port):QTcpServer(parent)
{
    QTcpServer::listen(QHostAddress::Any, port); //监听
}

//重写incomingConnection
//当新连接可用时，qtcpserver将调用此虚拟函数。socket descriptor参数是接受连接的本机套接字描述符。
void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpclientsocket = new TcpClientSocket(this);//只要有新的连接就生成一个新的通信套接字
    //将新创建的通信套接字描述符指定为参数socketdescriptor
    tcpclientsocket->setSocketDescriptor(socketDescriptor);

    //将这个套接字加入客户端套接字列表中
    tcpclientsocketlist.append(tcpclientsocket);


    //接收到tcpclientsocket发送过来的更新界面的信号
    connect(tcpclientsocket, &TcpClientSocket::updateserver, this, &Server::sliotupdateserver);
    connect(tcpclientsocket, &TcpClientSocket::clientdisconnected, this, &Server::slotclientdisconnect);

}

void Server::sliotupdateserver(QString msg, int length)
{
    //将这个信号发送给界面
    emit updateserver(msg, length);

    QTcpSocket *item;
    //将收到的信息发送给每个客户端,从套接字列表中找到需要接收的套接字
    for(int i = 0; i < tcpclientsocketlist.count(); i++)
    {
        item = tcpclientsocketlist.at(i);
//        if(item->write((char*)msg.toUtf8().data(), length) != length)
//        {
//            continue;
//        }
        item->write(msg.toUtf8().data());
    }

}

void Server::slotclientdisconnect(int descriptor)
{
    for(int i = 0; i < tcpclientsocketlist.count(); i++)
    {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        if(item->socketDescriptor() == descriptor)
        {
            tcpclientsocketlist.removeAt(i);//如果有客户端断开连接， 就将列表中的套接字删除
            return;
        }
    }
    return;
}

