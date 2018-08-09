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
    DLOG("Display screen : %d", screenId);
    if(m_screenAdapter && m_screenAdapter->getCurrentScreen() == screenId) {
        return;
    }
    m_screenAdapter->setScreenId(screenId);
    m_screenAdapter->createScreen();
    connect(DataManager::getInstance(), SIGNAL(dataChanged(int)), m_screenAdapter, SLOT(updateAppData(int)), Qt::UniqueConnection);
}

void DataLogger::hmiHandle(QString objectName, int eventId, QString param){
    HLOG("Received event: %d, params - %s", eventId, param.toStdString().data());

    switch (eventId) {
    case DataEnum::HMI_BUTTON_HOME: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_HOME) {
            showScreen(ICS_HOME);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_AUDIO: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_AUDIO) {
            showScreen(ICS_HOME);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_SETTING: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_SETTING) {
            showScreen(ICS_HOME);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_CLIMATE: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_CLIMATE) {
            showScreen(ICS_HOME);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_DATA: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_DATA) {
            showScreen(ICS_HOME);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_NETWORK: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_NETWORK) {
            showScreen(ICS_HOME);
        }
        break;
    }
    default:
        break;
    }
}


