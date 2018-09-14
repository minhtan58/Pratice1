#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

//#define HOST "127.0.0.1"
//#define PORT "1234"
class WinDow;
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    Q_INVOKABLE void sendData(QString);
    Q_INVOKABLE bool connectedToHost();
    Q_INVOKABLE void disConnect();


private:
    QTcpSocket *socket;
signals:

public slots:

};

#endif // CLIENT_H
