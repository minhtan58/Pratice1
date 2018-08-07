#ifndef THREADHANDLER_H
#define THREADHANDLER_H

#include <QObject>
#include "TimeSystemHandler.h"
#include "ThreadHandler.h"

class ThreadHandler : public QObject
{
    Q_OBJECT
public:
    explicit ThreadHandler(QObject *parent = 0);
    ~ThreadHandler();
    void start();

private:
    TimeSystemHandler *m_timeSystem = nullptr;
    //SettingsHandler *m_settingsHandler = nullptr;
signals:

public slots:
};

#endif // THREADHANDLER_H
