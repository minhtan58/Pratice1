#include "ScreenAdapter.h"

ScreenAdapter::ScreenAdapter(QObject *parent) : QObject(parent)
{

}

ScreenAdapter::~ScreenAdapter()
{}

ScreenAdapter::createScreen(){
    qDebug() << "Load screen starting...";
    m_appContainer->setProperty("source", screenList.value(m_screenId));
    m_screenView = qvariant_cast<QObject*>(m_appContainer->property("item"));
    initAppData();
    qDebug() << "Load screen " << m_screenId << "done";
}

int ScreenAdapter::getCurrentScreen()
{
    return m_screenId;
}

void ScreenAdapter::initAppData(){

}
