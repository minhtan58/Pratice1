#include "ManagerEvent.h"

ManagerEvent::ManagerEvent(QObject *parent) : QObject(parent){
    qmlRegisterType<EventID>("EventID", 1, 0, "EventID");
}

void ManagerEvent::initWindow(){
    m_engine.rootContext()->setContextProperty("UIBridge", UIBridge::getInstance());   //Tao cau noi giua QML va C++
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_mySerialPort = new MySerialPort(this);
    m_engine.rootContext()->setContextProperty("MySerialPort", m_mySerialPort);

    m_myTcpSocket = new MyTcpSocket(this);
    m_engine.rootContext()->setContextProperty("MyTcpSocket", m_myTcpSocket);

    connect(UIBridge::getInstance(), SIGNAL(hmiEvent(int, QString)), this, SLOT(hmiHandle(int,QString)));

    m_screenContainer = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("screenContainer");
    m_screenContainer->setProperty("source", "qrc:/home.qml");
}

void ManagerEvent::hmiHandle(int eventId, QString param){
    switch (eventId) {
    case EventID::ICS_HOME:
    {
        m_screenContainer->setProperty("source", "qrc:/home.qml");
        qDebug() << "vao1";
        break;
    }
    case EventID::ICS_CONNECTION_PORTCOM:
    {
        m_screenContainer->setProperty("source", "qrc:/ics_connection_portcom.qml");
        qDebug() << "vao2";
        break;
    }
    case EventID::ICS_CONNECTION_INTERNET:
    {
        m_screenContainer->setProperty("source", "qrc:/ics_connection_internet.qml");
        qDebug() << "vao3";
        break;
    }
    default:
        break;
    }
}
