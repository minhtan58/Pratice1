#include "MySerialPort.h"

MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    m_serial = new QSerialPort(this);
    connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
}

void MySerialPort::openSerialPort(QString portCom)
{
    if(m_serial->portName() == portCom) {
        if(m_serial->isOpen()) {
            SETDPDATA(EnumID::DP_SERIALPORT_TEST_CONNECTION, QString::number(int(IS_CONNECTED)));
            return;
        }
    }

    m_serial->setPortName(portCom);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        SETDPDATA(EnumID::DP_SERIALPORT_TEST_CONNECTION, QString::number(int(IS_CONNECTED)));
        return;
    } else {
        SETDPDATA(EnumID::DP_SERIALPORT_TEST_CONNECTION, QString::number(int(IS_CONNECTED)));
        return;
    }
}

void MySerialPort::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();

    showStatus(tr("Disconnected"));
}

void MySerialPort::writeData(const QByteArray &data)
{
    m_serial->write(data);
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
   QByteArray data = m_serial->readAll();
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
