#include "MySerialPort.h"

MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
    //openSerialPort();
}

void MySerialPort::openSerialPort()
{
    serial->setPortName("COM2");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        showStatus("Connectedd");
    } else {
        showStatus(tr("Open error"));
    }
}

void MySerialPort::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();

    showStatus(tr("Disconnected"));
}

void MySerialPort::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MySerialPort::readData()
{
   QByteArray data = serial->readAll();

   qDebug() << data;
}

void MySerialPort::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        closeSerialPort();
    }
}

void MySerialPort::showStatus(const QString &message)
{
    qDebug() << message;
}
