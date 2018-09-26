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
        qDebug() << "OK";
        break;
    }

    default:
        break;
    }
}

void SerialPortHandler::eventHandler(QString objectName, int eventId, QString param) {
    Q_UNUSED(objectName)
    switch (eventId) {
    case EnumID::HMI_TAB_SELECT: {
        break;
    }
    case EnumID::HMI_BUTTON_TEST_CONNECTIONS_SERIALPORT: {
        //QStringList paramList = getListParam(param);
        SENDEVENT("" , EnumID::HMI_REQUEST_COMMON_POPUP, "3000,Connecting...");
        SETDPDATA(EnumID::DP_SERIALPORT_TEST_CONNECTION, QString::number(int(IS_CHECKING)));
        m_serialPort->openSerialPort(param);
        break;
    }
    default:
        break;
    }
}
