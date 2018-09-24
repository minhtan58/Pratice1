#ifndef BASETHREADS_H
#define BASETHREADS_H

#include <QObject>

#include "SerialPortHandler.h"

class BaseThreads : public QObject
{
    Q_OBJECT
public:
    explicit BaseThreads(QObject *parent = nullptr);
    ~BaseThreads();
    void start();

private:
    SerialPortHandlerThread *m_serialPortHandler = nullptr;

signals:

public slots:

};

#endif // BASETHREADS_H
