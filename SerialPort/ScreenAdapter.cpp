#include "ScreenAdapter.h"

ScreenAdapter::ScreenAdapter(QObject *container, QObject *parent)
    : QObject(parent)
    , m_screenContainer(container)
    , m_screenId(-1)
{
    //m_screenContainer = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("screenContainer");
}

ScreenAdapter::~ScreenAdapter()
{}

void ScreenAdapter::createScreen() {
    qDebug() << "Load screen starting...";
    m_screenContainer->setProperty("source", mapScreen.value(m_screenId));
    m_screenView = qvariant_cast<QObject*>(m_screenContainer->property("item"));
    //initAppData();
    qDebug() << "Load screen " << m_screenId << "done";
}

int ScreenAdapter::getCurrentScreen() {
    return m_screenId;
}

void ScreenAdapter::setScreenId(int screenId) {
    m_screenId = screenId;
}

void ScreenAdapter::initAppData() {
    switch (m_screenId) {
    case ICS_DATA_VIEW: {
        SETPROPERTY("viewO2", "textValue", GETDPDATA(EnumID::DP_FROM_PORTCOM));

        break;
    }
    case ICS_CONNECTION_PORTCOM: {
        SETPROPERTY("viewO2", "textValue", GETDPDATA(EnumID::DP_FROM_PORTCOM));

        break;
    }
    case ICS_CONNECTION_NETWORK: {
        SETPROPERTY("viewO2", "textValue", GETDPDATA(EnumID::DP_FROM_NETWORK));

        break;
    }
    case ICS_HOME: {
        SETPROPERTY("viewO2", "textValue", GETDPDATA(EnumID::DP_DATE));

        break;
    }
    default:
        break;
    }
}

void ScreenAdapter::updateAppdata(int dpid) {

}
