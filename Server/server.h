#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    explicit Server(QObject *parent = 0);

    ~Server();
    Q_INVOKABLE void startServer();

    QString message() const;
    void setMessage(const QString &message);

private:
    QTcpServer *server;
    QString m_message;

signals:
    void messageChanged();

public slots:
    void newConnect();
    void readData();
};

#endif // SERVER_H
