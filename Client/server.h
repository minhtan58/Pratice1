#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>


class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    //Q_INVOKABLE void receiveData();
    Q_INVOKABLE void startServer();

private:
    QTcpServer *Server;
signals:

public slots:
    void newConnect();
    void readData();
};

#endif // SERVER_H
