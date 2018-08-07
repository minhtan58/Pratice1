#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <QObject>

#include "DataManager.h"
#include "Defines.h"

class UIBridge : public QObject
{
    Q_OBJECT
public:
    explicit UIBridge(QObject *parent = 0);
    static UIBridge *getInstance();
    ~UIBridge;
    Q_INVOKABLE QString getDPData();
    Q_INVOKABLE void setDPData(int dpid, QVariant value);
    Q_INVOKABLE void log(QString msg);

    void sendEvent (QString objectName, int eventId, QString param);
private:
    static UIBridge *m_uiBridge;
signals:
    void hmiEvent(QString objectName, int eventId, QString param);

public slots:
};

#endif // UIBRIDGE_H
