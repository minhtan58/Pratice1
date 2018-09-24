#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

class MySerialPort : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit MySerialPort(QObject *parent = 0);
    QString message() const;
    QString getData(int dpId) const;

signals:
    void messageChanged();
    void readComplete();

public slots:
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void setMessage(const QString &m);
    void openSerialPort(QString portCom);
    void closeSerialPort();
    void writeData(const QByteArray &data);

private:
    QString m_dataChange;
    void showStatus(const QString &status);
    QSerialPort *serial = nullptr;
};

#endif // MYSERIALPORT_H

