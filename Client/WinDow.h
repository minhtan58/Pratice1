#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>


#include "UIBridge.h"
#include "eventid.h"
#include "client.h"
#include "status.h"


class WinDow : public QObject
{
    Q_OBJECT

public:
    QQuickItem *m_screenContainer = nullptr;
    QQuickItem *m_popupContainer = nullptr;
    explicit WinDow(QObject *parent = 0);



signals:



public slots:
    void hmiHandle(int eventID, QString params);

private:
    QQmlApplicationEngine m_engine;
    UIBridge *m_uiBridge = nullptr;
    Client *m_client;
    Status *m_status;

    void initWindow();
};

#endif // WINDOW_H
