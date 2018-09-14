#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    Server = new QTcpServer(this);
    connect(Server, SIGNAL(newConnection()), this, SLOT(newConnect()));
}
void server::startServer()
{
    if(!Server->listen(QHostAddress::Any, 1234)) {
        qDebug()<< "Server could not start";
    }
    else {
        qDebug()<< "Server started";
    }
}

void server::newConnect()
{
    QTcpSocket *Socket = Server->nextPendingConnection();
    qDebug() << "New connection" << Socket->peerAddress();
    connect(Socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void server::readData()
{
    QTcpSocket *Socket =  qobject_cast<QTcpSocket*>(sender());
    qDebug() << Socket->readAll();
}
//void server::receiveData()
//{
//    QTcpSocket *Socket = Server->nextPendingConnection();
//    qDebug() << Socket->readAll();

//}
