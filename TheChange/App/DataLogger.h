#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include <QGuiApplication>
#include <QDebug>
#include <QThread>
#include <QtQml>

#include "QmlConstants.h"
#include "UIBridge.h"
#include "Defines.h"
#include "DataEnum.h"
#include "ScreenAdapter.h"
#include "TaskbarAdapter.h"
#include "DataManager.h"
#include "ThreadHandler.h"

class DataLogger : public QObject
{
    Q_OBJECT
public:
    explicit DataLogger(QObject *parent = 0);
    ~DataLogger();    
    void exec();

private:
    QQmlApplicationEngine m_qmlAppEngine;
    QMLConstants m_Constant;
    UIBridge m_UIBridge;
    ThreadHandler m_threadHatndler;
    ScreenAdapter *m_screenAdapter = nullptr;
    TaskbarAdapter *m_taskBarAdapter = nullptr;

    void initDatalogger();
    void showScreen(int screenId);

    void showOverlay(int overlayId, int timeout, int layer, QString message);
    void hideOverlay();

signals:

public slots:
    void hmiHandle(QString objectName, int eventId, QString param);
};

#endif // DATALOGGER_H
