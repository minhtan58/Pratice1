#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <QObject>
#include "Enum.h"

class UIBridge : public QObject
{
    Q_OBJECT
public:
    explicit UIBridge(QObject *parent = 0);
    static UIBridge *getInstance();
    ~UIBridge();

    void sendEvent(int eventId, QString param);
private:
    static UIBridge *m_uiBridge;
signals:
    void hmiEvent(int eventId, QString param);
public slots:
};

#endif // UIBRIDGE_H
