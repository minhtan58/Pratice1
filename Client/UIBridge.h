#ifndef UIBRIDGE_H
#define UIBRIDGE_H
#include "eventid.h"


#include <QObject>
#include <QTime>

class UIBridge : public QObject
{
    Q_OBJECT
private:
    QString m_IPAddress;
    QTime currenttime;
public:
    explicit UIBridge(QObject *parent = 0);
    Q_INVOKABLE QString getIPAddress();
    Q_INVOKABLE void setIPAddress(QString newValue);
    Q_INVOKABLE QString getTime();

signals:
    void hmiEvent(int eventID, QString);

public slots:
};

#endif // UIBRIDGE_H
