#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "QmlConstants.h"
#include "UIBridge.h"

class DataLogger : public QObject
{
    Q_OBJECT
public:
    explicit DataLogger(QObject *parent = 0);
    void initDatalogger();
private:
    QQmlApplicationEngine m_Engine;
    QMLConstants m_Constant;
    UIBridge m_UIBridge;

    void showScreen(int screenId);

signals:

public slots:
};

#endif // DATALOGGER_H
