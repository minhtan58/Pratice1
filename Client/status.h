#ifndef STATUS_H
#define STATUS_H

#include <QObject>

class Status : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    QString m_message;

public:
    explicit Status(QObject *parent = 0);

    QString message() const;
//    Q_INVOKABLE void readData(QString);
signals:

    void messageChanged();

public slots:

    void setMessage(const QString &m);

};

#endif // STATUS_H
