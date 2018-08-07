#include "ThreadHandler.h"

ThreadHandler::ThreadHandler(QObject *parent) : QObject(parent)
{
    HLOG("Create");
    m_timeSystem = new TimeSystemHandler(this);
}

ThreadHandler::~ThreadHandler(){
    //m_timeSystem->quit();
}

void ThreadHandler::start()
{
    //m_timeSystem->start();
}
