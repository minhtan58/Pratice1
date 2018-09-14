#include "WinDow.h"
#include "eventid.h"

WinDow::WinDow(QObject *parent) : QObject(parent)
{
    initWindow();
}

void WinDow::hmiHandle(int eventID, QString params)
{
    switch (eventID) {
    case EventID::Home_Screen:
    {
        m_screenContainer->setProperty("source", "qrc:/Home.qml");
        break;
    }
    case EventID::Working_Screen:
    {
        m_screenContainer->setProperty("source", "qrc:/Working.qml");
        break;
    }
    case EventID::Connetion_Screen:
    {
        m_screenContainer->setProperty("source", "qrc:/Connection.qml");
        break;
    } 
    case EventID::Notification_Failed_Screen:
    {
        m_popupContainer->setProperty("source","qrc:/Notification_Failed.qml");
        break;
    }
    case EventID::Notification_Success_Screen:
    {
        m_popupContainer->setProperty("source","qrc:/Notification_Success.qml");
        break;
    }
    case EventID::Connect_Success_Notification:
    {
        m_popupContainer->setProperty("source","qrc:/Connect_Success_Notification.qml");
        break;
    }
    case EventID::Connect_Failed_Notification:
    {
        m_popupContainer->setProperty("source","qrc:/Connect_Failed_Notification.qml");
        break;
    }
    case EventID::Stop_Connect_Notification:
    {
        m_popupContainer->setProperty("source","qrc:/Stop_Connect_Notification.qml");
        break;
    }
    case EventID::None_Screen:
    {
        m_popupContainer->setProperty("source","");
        break;
    }
    case EventID::Send_Data_To_Server:
    {
        m_client->sendData(params);
    }
    default:
        break;
    }
}


void WinDow::initWindow()
{

    m_uiBridge = new UIBridge(this);
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    m_engine.rootContext()->setContextProperty("UIBridge", m_uiBridge);   //Tao cau noi giua QML va C++


    m_client = new Client(this);
    m_engine.rootContext()->setContextProperty("Client", m_client);

//    m_server = new server(this);
//    m_engine.rootContext()->setContextProperty("Server",m_server);
//    m_server->startServer();

    m_status = new Status(this);
    m_engine.rootContext()->setContextProperty("Status",m_status);




    m_screenContainer = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("screenContainer");
    m_popupContainer = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("popupContainer");

    m_screenContainer->setProperty("source", "qrc:/LoginForm.qml");

}

































