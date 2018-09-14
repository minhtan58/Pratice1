#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(parent);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnect()));
}

Server::~Server()
{
    delete server;
}


void Server::startServer()
{
    if(!server->listen(QHostAddress::Any, 1234)) {
        qDebug()<< "Server could not start";
    }
    else {
        qDebug()<< "Server started";
    }
}

QString Server::message() const
{
    return m_message;
}

void Server::setMessage(const QString &message)
{
    if(m_message != message) {
        m_message = message;
        emit messageChanged();
    }
}

void Server::newConnect()
{
    QTcpSocket *Socket = server->nextPendingConnection();
    qDebug() << "New connection" << Socket->peerAddress();
    connect(Socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void Server::readData()
{
    QTcpSocket *Socket = qobject_cast<QTcpSocket*>(QObject::sender());
    QString revMessage = Socket->readAll();
    setMessage(revMessage);
}
