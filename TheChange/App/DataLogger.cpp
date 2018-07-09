#include "DataLogger.h"
#include <QGuiApplication>

#include <QDebug>
#include <QThread>
#include <QQmlContext>

DataLogger::DataLogger(QObject *parent) : QObject(parent)
{

}

void DataLogger::initDatalogger(){
    //m_Engine QmlEngine
    QQmlContext *context = m_Engine.rootContext();
    context -> setContextProperty("QMLConstants", &m_Constant);
    context -> setContextProperty("UIBridge", &m_UIBridge);

    m_Engine.load(QUrl(QStringLiteral("qrc:/resources/main.qml")));
    //connect(DataManager::getInstance(), SIGNAL(dataChanged(int)), m_topBarAdapter, SLOT(updateAppData(int)), Qt::UniqueConnection);


}

void DataLogger::showScreen(int screenId){
    qDebug()    << "[" << QThread::currentThreadId() << "][" << Q_FUNC_INFO << "]";


}
