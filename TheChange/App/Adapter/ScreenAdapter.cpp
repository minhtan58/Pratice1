#include "ScreenAdapter.h"

ScreenAdapter::ScreenAdapter(QQmlApplicationEngine *qmlAppEngine, QObject *parent)
    : QObject(parent)
    , m_qmlAppEngine(qmlAppEngine)
    , m_screenId(-1)
{
    m_appContainer = m_qmlAppEngine->rootObjects().at(0)->findChild<QQuickItem*>("mainScreen");
    connect(UIBridge::getInstance(), SIGNAL(hmiEvent(QString,int,QString)), this, SLOT(eventHandler(QString,int,QString)));
}

ScreenAdapter::~ScreenAdapter()
{}

void ScreenAdapter::createScreen(){
    HLOG("Start create screen");
    m_appContainer->setProperty("source", ScreenList.value(m_screenId));
    m_screenView = qvariant_cast<QObject*>(m_appContainer->property("item"));
    initAppData();
}

void ScreenAdapter::initAppData(){
    HLOG("Update data for this screen");

}

void ScreenAdapter::eventHandler(QString objectName, int eventId, QString param){

}

int ScreenAdapter::getCurrentScreen(){
    return m_screenId;
}

void ScreenAdapter::setScreenId(int screenId){
    m_screenId = screenId;
}
