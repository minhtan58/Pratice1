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

void DataLogger::exec(){
    DataManager::getInstance();
    initDatalogger();

}

void DataLogger::initDatalogger(){
    //m_threadHatndler = new ThreadHandler(this);
    connect(UIBridge::getInstance(), SIGNAL(hmiEvent(QString,int,QString)), this, SLOT(hmiHandle(QString,int,QString)));

}

void DataLogger::showScreen(int screenId){
    qDebug()    << "[" << QThread::currentThreadId() << "][" << Q_FUNC_INFO << "]";

}

void DataLogger::hmiHandle(QString objectName, int eventId, QString param){
    HLOG("Received event: %d, params - %s", eventId, param.toStdString().data());

    switch (eventId) {
    case DataEnum::HMI_BUTTON_HOME: {
        if(m_screenAdapter->getCurrentScreen() < SCR_SETTINGS_OVERVIEW
                || m_screenAdapter->getCurrentScreen() > SCR_SETTINGS_DEVELOPMENT) {
            showScreen(SCR_SETTINGS_OVERVIEW);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_SETTING: {
        if(m_screenAdapter->getCurrentScreen() < SCR_SETTINGS_OVERVIEW
                || m_screenAdapter->getCurrentScreen() > SCR_SETTINGS_DEVELOPMENT) {
            showScreen(SCR_SETTINGS_OVERVIEW);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_HISTORY: {
        showScreen(SCR_HISTORY_DATAVIEW);
        break;
    }
    default:
        break;
    }
}


