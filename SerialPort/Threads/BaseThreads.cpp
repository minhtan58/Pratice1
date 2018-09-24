#include "BaseThreads.h"

BaseThreads::BaseThreads(QObject *parent) : QObject(parent)
{
    m_serialPortHandler = new SerialPortHandlerThread(this);
}

BaseThreads::~BaseThreads() {
    m_serialPortHandler->quit();
}

void BaseThreads::start() {
    m_serialPortHandler->start();
}
