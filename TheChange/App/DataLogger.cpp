#include "DataLogger.h"

DataLogger::DataLogger(QObject *parent) : QObject(parent)
{
    //HLOG("Create main");
    qmlRegisterType<UIBridge>("UIBridge", 1, 0, "UIBridge");
    qmlRegisterType<DataEnum>("DataEnum", 1, 0, "DataEnum");
    qRegisterMetaType<DataEnum::DatapoolID>("DataEnum::DatapoolID");
    qRegisterMetaType<DataEnum::HMIEvent>("DataEnum::HMIEvent");
}

DataLogger::~DataLogger(){}

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
