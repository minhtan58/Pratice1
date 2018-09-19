#include "MyTcpSocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) : QObject(parent)
{

}

void MyTcpSocket::doConnect(QString ipAdress,int port)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "Connecting...";

    // this is not blocking call
    socket->connectToHost(ipAdress,port);

    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void MyTcpSocket::connected(){
    qDebug() << "Connected";
}

void MyTcpSocket::disconnected(){
    qDebug() << "Disconnected";
    socket->disconnectFromHost();
}

QString MyTcpSocket::message() const
{
    return m_dataChange;
}

void MyTcpSocket::setMessage(const QString &m)
{
        if (m_dataChange == m)
            return;
        m_dataChange = m;
        emit messageChanged();
}

void MyTcpSocket::writeData(const QByteArray &data)
{
    socket->write(data);
}

void MyTcpSocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void MyTcpSocket::readyRead(){
    QByteArray data = socket->readAll();
    m_dataChange = QString::fromUtf8(data);
    qDebug() << data;
    emit messageChanged();
}
