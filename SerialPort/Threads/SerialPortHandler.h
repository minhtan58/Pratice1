#ifndef SERIALPORTHANDLER_H
#define SERIALPORTHANDLER_H

#include <QObject>
#include "MySerialPort.h"

class SerialPortHandler : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortHandler(QObject *parent = 0);

signals:

public slots:

private:
    MySerialPort *m_serialPort = nullptr;

    void readDConChanel(int dataId);
};

#endif // SERIALPORTHANDLER_H
