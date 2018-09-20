#include "SerialPortHandler.h"

SerialPortHandler::SerialPortHandler(QObject *parent) : QObject(parent)
{
    m_serialPort = new MySerialPort();
}
