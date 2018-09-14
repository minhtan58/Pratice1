#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

class MySerialPort : public QObject
{
    Q_OBJECT
public:
    explicit MySerialPort(QObject *parent = 0);

signals:

public slots:
    void openSerialPort(QString portCom);
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void showStatus(const QString &status);
    QSerialPort *serial = nullptr;
};

#endif // MYSERIALPORT_H

