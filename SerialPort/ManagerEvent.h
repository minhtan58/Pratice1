#ifndef MANAGEREVENT_H
#define MANAGEREVENT_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>

#include "UIBridge.h"
#include "MySerialPort.h"
#include "MyTcpSocket.h"
#include "Enum.h"

class ManagerEvent : public QObject
{
    Q_OBJECT
public:
    explicit ManagerEvent(QObject *parent = 0);
    QQuickItem *m_screenContainer = nullptr;
    void sendEvent(int eventId, QString params);
    void initWindow();
private:
    QQmlApplicationEngine m_engine;
    UIBridge *m_uiBridge;
    MySerialPort *m_mySerialPort = nullptr;
    MyTcpSocket *m_myTcpSocket = nullptr;
signals:

public slots:
    void hmiHandle(int eventId, QString param);
};

#endif // MANAGEREVENT_H
