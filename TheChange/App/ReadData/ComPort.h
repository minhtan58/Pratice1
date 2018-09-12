#ifndef COMPORT_H
#define COMPORT_H

#include <QObject>
#include <QTimer>
#include <QtSerialPort/QSerialPort>

#include "DataEnum.h"
#include "Defines.h"

class ComPort : public QObject
{
    Q_OBJECT
public:
    explicit ComPort(QObject *parent = 0);
    
    enum {
        DCON_GET_MODULE_NAME = 0x00,
        DCON_GET_FIRMWARE,
        DCON_GET_MODULE_CONFIGURE,
        DCON_SET_MODULE_CONFIGURE,
        DCON_GET_CHANEL_ENABLE_STATUS,
        DCON_SET_CHANEL_ENABLE_STATUS,
        DCON_READ_AI_ALL
    };

    enum ReadStatus {
        STATUS_READ_IDLE,
        STATUS_READ_STARTED,
        STATUS_READ_FINISHED
    };
    
    void startReadData(int msec);
    QString getValue(int i);

private:
    QSerialPort *m_serial = nullptr;
    QTimer *m_readScheduce = nullptr;
    QTimer *m_updateStatus = nullptr;
    QMap<int, QString> m_command;
    QString m_valueRegister[8];
    int m_readStatus;

    void configSerialPort();
    void initCommand();
    void sendCommand(int commandId, int addressId);
    void alynasisDConMessage(QByteArray message);

signals:
    void ReadComplete();

public slots:
    void sltReadSerialData();
    void sltRequestReadScheduce();
    void testConnection(QString portName, int baudrate);
    void sltConnectSerialPort();
    void sltUpdateStatus();
};

#endif // COMPORT_H
