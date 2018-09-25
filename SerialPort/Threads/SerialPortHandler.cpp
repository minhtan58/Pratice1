#include "SerialPortHandler.h"

SerialPortHandler::SerialPortHandler(QObject *parent) : QObject(parent)
{
    m_serialPort = new MySerialPort();
    connect(m_serialPort, SIGNAL(readComplete()), this, SLOT(readDataType()), Qt::UniqueConnection);
}

void SerialPortHandler::readDataType() {
    readData(EnumID::DP_FROM_PORTCOM);
    readData(EnumID::DP_FROM_NETWORK);
    qDebug() << "Okq";
}

void SerialPortHandler::readData(int dpId) {
    QString value = m_serialPort->getData(dpId);
    qDebug() << value;
    switch (dpId) {
    case EnumID::DP_FROM_PORTCOM : {
        SETDPDATA(EnumID::DP_PORTCOM, value);
        qDebug() << "OK";
        break;
    }

    case EnumID::DP_FROM_NETWORK : {
        SETDPDATA(EnumID::DP_NETWORK, value);
        qDebug() << "OK1";
        break;
    }

    default:
        break;
    }

}
