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

class DataLogger : public QObject
{
    Q_OBJECT
public:
    explicit DataLogger(QObject *parent = 0);
    ~DataLogger();
    void initDatalogger();
private:
    QQmlApplicationEngine m_Engine;
    QMLConstants m_Constant;
    UIBridge m_UIBridge;

    ScreenAdapter *m_screenAdapter = nullptr;

    void showScreen(int screenId);

signals:

public slots:
};

#endif // DATALOGGER_H
