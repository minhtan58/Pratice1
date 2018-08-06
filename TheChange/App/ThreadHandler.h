#ifndef THREADHANDLER_H
#define THREADHANDLER_H

#include <QObject>
#include "TimeSystemHandler.h"

class ThreadHandler : public QObject
{
    Q_OBJECT
public:
    explicit ThreadHandler(QObject *parent = nullptr);
private:
    TimeSystemHandler *m_timeSystem = nullptr;

signals:

public slots:
};

#endif // THREADHANDLER_H
