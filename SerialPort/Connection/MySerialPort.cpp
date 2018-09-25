#include "MySerialPort.h"

MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
}

void MySerialPort::openSerialPort(QString portCom)
{
    //serial->setPortName("COM2");
    serial->setPortName(portCom);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        showStatus("Connected");
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

QString MySerialPort::message() const
{
    return m_dataChange;
}

QString MySerialPort::getData(int dpId) const
{
    return m_dataChange;
}

void MySerialPort::setMessage(const QString &m)
{
        if (m_dataChange == m)
            return;
        m_dataChange = m;
        emit messageChanged();
}

void MySerialPort::readData()
{
   QByteArray data = serial->readAll();
   m_dataChange = QString::fromUtf8(data);   
   emit messageChanged();
   emit readComplete();
   qDebug() << "rev: " << data;
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
