#include "DataLogger.h"

DataLogger::DataLogger(QObject *parent) : QObject(parent)
{
    HLOG("Create main");
    //qmlRegisterType<UIBridge>("UIBridge", 1, 0, "UIBridge");
    qmlRegisterType<DataEnum>("DataEnum", 1, 0, "DataEnum");
    qRegisterMetaType<DataEnum::DatapoolID>("DataEnum::DatapoolID");
    qRegisterMetaType<DataEnum::HMIEvent>("DataEnum::HMIEvent");
}

DataLogger::~DataLogger(){}

void DataLogger::exec(){
    DataManager::getInstance();
    initDatalogger();
    showScreen(ICS_HOME);
}

void DataLogger::initDatalogger(){

    m_qmlAppEngine.rootContext()->setContextProperty("UIBridge", UIBridge::getInstance());
    m_qmlAppEngine.load(QUrl(QStringLiteral("qrc:/resources/main.qml")));

    m_screenAdapter = new ScreenAdapter(&m_qmlAppEngine, this);
    connect(UIBridge::getInstance(), SIGNAL(hmiEvent(QString,int,QString)), this, SLOT(hmiHandle(QString,int,QString)));
    m_taskBarAdapter = new TaskbarAdapter(m_qmlAppEngine.rootObjects().at(0)->findChild<QQuickItem*>("taskbarContainer"), this);
    connect(DataManager::getInstance(), SIGNAL(dataChanged(int)), m_taskBarAdapter, SLOT(updateAppData(int)), Qt::UniqueConnection);

}

void DataLogger::showScreen(int screenId){
    HLOG("Display screen : %d", screenId);
    if(m_screenAdapter && m_screenAdapter->getCurrentScreen() == screenId) {
        return;
    }
    m_screenAdapter->setScreenId(screenId);
    m_screenAdapter->createScreen();
    connect(DataManager::getInstance(), SIGNAL(dataChanged(int)), m_screenAdapter, SLOT(updateAppData(int)), Qt::UniqueConnection);
}

void DataLogger::showOverlay(int overlayId, int timeout, int layer, QString message){
    Q_UNUSED(message)
    HLOG("Create overlay screen:: %d", overlayId);
    QQuickItem *overlayStatus = m_qmlAppEngine.rootContext().at(0)->findChild<QQuickItem*>("overlayContainer");
    if(!overlayStatus) {
        DLOG("OverlayStatus null");
        return;
    }
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
            showScreen(ICS_AUDIO);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_SETTING: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_SETTING) {
            showScreen(ICS_SETTING);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_CLIMATE: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_CLIMATE) {
            showScreen(ICS_CLIMATE);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_DATA: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_DATA) {
            showScreen(ICS_DATA);
        }
        break;
    }
    case DataEnum::HMI_BUTTON_NETWORK: {
        if(m_screenAdapter && m_screenAdapter->getCurrentScreen() != ICS_NETWORK) {
            showScreen(ICS_NETWORK);
        }
        break;
    }
    default:
        break;
    }
}


