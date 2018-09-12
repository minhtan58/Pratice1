#ifndef SERIALPORTHANDLER_H
#define SERIALPORTHANDLER_H

#include <QObject>
#include <QThread>
//#include <QSerialPort>
//#include <QSerialPortInfo>

#include "ComPort.h"

class SerialPortHandler : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortHandler(QObject *parent = 0);
    void updateSerialPortList();
private:
    ComPort *m_comPort = nullptr;

signals:

public slots:
};

#endif // SERIALPORTHANDLER_H
