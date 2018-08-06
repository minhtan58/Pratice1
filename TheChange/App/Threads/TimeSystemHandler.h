#ifndef TIMESYSTEMHANDLER_H
#define TIMESYSTEMHANDLER_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDateTime>
#include <QProcess>

#include "Defines.h"
#include "DataEnum.h"
#include "DataManager.h"

class TimeSystemHandler : public QObject
{
    Q_OBJECT
public:
    explicit TimeSystemHandler(QObject *parent = nullptr);

public slots:
    void updateTimeSystem();
    void eventHandler(QString objectName, int eventID, QString param);
    //void updateAppData(int dpId);
};

#endif // TIMESYSTEMHANDLER_H
