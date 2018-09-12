#include "ComPort.h"

#define ADDRESS_ID                          QString("[_ADDRESS_ID_]")
#define COMMAND_BUIDER(command, addressId)  command.replace(ADDRESS_ID, QString::number(addressId, 16).toUpper().rightJustified(2, '0'))

ComPort::ComPort(QObject *parent) : QObject(parent)
{
    m_readStatus = STATUS_READ_IDLE;
    m_serial = new QSerialPort(this);
    m_readScheduce = new QTimer(this);
    m_updateStatus = new QTimer(this);
    configSerialPort();
    initCommand();

    connect(m_readScheduce, SIGNAL(timeout()), this, SLOT(sltRequestReadScheduce()), Qt::UniqueConnection);
    connect(m_updateStatus, SIGNAL(timeout()), this, SLOT(sltUpdateStatus()), Qt::UniqueConnection);
    m_updateStatus->start(TIME_UPDATE_STATUS);
}

void ComPort::configSerialPort(){
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setStopBits(QSerialPort::OneStop);
}

void ComPort::sltRequestReadScheduce(){
    if(!m_serial->isOpen())
        return;
    sendCommand(DCON_READ_AI_ALL, 1);
}

void ComPort::sendCommand(int commandId, int addressId){
    if(m_serial->isOpen()){
        QString command = m_command.value(commandId);
        command = COMMAND_BUIDER(command, addressId);
        m_serial->write(command.toStdString().c_str());
    }
}

void ComPort::initCommand()
{
    m_command.insert(DCON_GET_MODULE_NAME,              QString("$[_ADDRESS_ID_]M\r"));
    m_command.insert(DCON_GET_FIRMWARE,                 QString("$[_ADDRESS_ID_]F\r"));
    m_command.insert(DCON_GET_MODULE_CONFIGURE,         QString("$[_ADDRESS_ID_]2\r"));
    m_command.insert(DCON_SET_MODULE_CONFIGURE,         QString("%[_ADDRESS_ID_]010D0A00\r"));
    m_command.insert(DCON_GET_CHANEL_ENABLE_STATUS,     QString("$[_ADDRESS_ID_]6\r"));
    m_command.insert(DCON_SET_CHANEL_ENABLE_STATUS,     QString("$[_ADDRESS_ID_]5FF\r"));
    m_command.insert(DCON_READ_AI_ALL,                  QString("#[_ADDRESS_ID_]\r"));
    for (int i = 0; i < 8; ++i) {
        m_valueRegister[i] = "";
    }
}

void ComPort::sendCommand(int commandId, int addressId)
{
    if(m_serial->isOpen()) {
        QString command = m_command.value(commandId);
        command = COMMAND_BUIDER(command, addressId);
        m_serial->write(command.toStdString().c_str());
        //DLOG("Send command: %s", command.toStdString().c_str());
    }
}
void ComPort::startReadData(int msec){
    if(msec <= 0){
        HLOG("Serial interval invalid");
        return;
    }
    m_readScheduce->start(msec);
}

void ComPort::sltConnectSerialPort(){
    if(m_serial->isOpen()){
        if(m_serial->portName() != GETDPDATA(DataEnum::DP_SETTINGS_SERIALPORT_PORTNAME)
                || m_serial->baudRate() != GETDPDATA(DataEnum::DP_SETTINGS_SERIALPORT_BAUDRATE).toInt()){
            m_serial->close();
        } else {
            return;
        }
    }

    if(!m_serial->isOpen()){
        m_serial->setPortName(GETDPDATA(DataEnum::DP_SETTINGS_SERIALPORT_PORTNAME));
        m_serial->setBaudRate(GETDPDATA(DataEnum::DP_SETTINGS_SERIALPORT_BAUDRATE).toUInt());
        if(m_serial->open(QIODevice::ReadWrite)){
            startReadData(GETDPDATA(DataEnum::DP_SETTINGS_SERIALPORT_INTERVAL).toUInt);
        }
    }
}
