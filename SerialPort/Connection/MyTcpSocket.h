#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class MyTcpSocket : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    explicit MyTcpSocket(QObject *parent = 0);
    Q_INVOKABLE void doConnect(QString ipAdress,int port);
    QString message() const;

private:
    QTcpSocket *socket = nullptr;
    QString m_dataChange;

signals:
    void messageChanged();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void writeData(const QByteArray &data);
    void setMessage(const QString &m);
};

#endif // MYTCPSOCKET_H
