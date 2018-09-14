#include "client.h"
#include "WinDow.h"
Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

}

void Client::sendData(QString value)
{
    //    bool check_connect = false;
    //    if(socket->state() != QAbstractSocket::ConnectedState) {
    //        connectToHost();
    //    }

    //    if(socket->state() == QAbstractSocket::ConnectedState) {
    //        check_connect = true;
    //    if(Client::connectToHost() == true){



    //$[TIME,%1][CODE,%2][CO,%3][NO2,%4][PM10,%5][PM25,%6]\r\n

    socket->write(value.toLocal8Bit() + "\n\r");
    if(socket->waitForBytesWritten()) {
        qDebug() <<"Connected!" << "\r\n";
    }
    else {
        qDebug() <<"Not Connected!" << "\r\n";
    }
}

bool Client::connectedToHost()
{
    WinDow* parentWindow = (WinDow*)this->parent();


    QString ip_addess = parentWindow->m_screenContainer->findChild<QQuickItem*>("ip_addess")->property("text").toString();
    QString port_to_connect = parentWindow->m_screenContainer->findChild<QQuickItem*>("port_to_connect")->property("text").toString();

    socket->connectToHost(ip_addess, port_to_connect.toInt());
    bool check_connect = socket->waitForConnected(3000);
    return check_connect;

}

void Client::disConnect()
{
    socket->disconnectFromHost();
}
