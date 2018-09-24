#include "ManagerEvent.h"

ManagerEvent::ManagerEvent(QObject *parent) : QObject(parent){
    qmlRegisterType<EnumID>("EnumID", 1, 0, "EnumID");
}

void ManagerEvent::initWindow(){
    ManagerData::getInstance();

    m_engine.rootContext()->setContextProperty("UIBridge", UIBridge::getInstance());   //Tao cau noi giua QML va C++
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_mySerialPort = new MySerialPort(this);
    m_engine.rootContext()->setContextProperty("MySerialPort", m_mySerialPort);

    m_myTcpSocket = new MyTcpSocket(this);
    m_engine.rootContext()->setContextProperty("MyTcpSocket", m_myTcpSocket);

    connect(UIBridge::getInstance(), SIGNAL(hmiEvent(QString, int, QString)), this, SLOT(hmiHandle(QString, int,QString)));

//    m_screenContainer = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("screenContainer");
//    m_screenContainer->setProperty("source", "qrc:/Screen/home.qml");

    m_screenAdapter = new ScreenAdapter(m_engine.rootObjects().at(0)->findChild<QQuickItem*>("screenContainer"), this);
    m_baseThreads->start();
    showScreen(ICS_HOME);

}

void ManagerEvent::showScreen(int screenId){
    qDebug() << "Display screen -" << screenId;
    if(m_screenAdapter && m_screenAdapter->getCurrentScreen() == screenId)
        return;

    m_screenAdapter->setScreenId(screenId);
    m_screenAdapter->createScreen();

}

void ManagerEvent::showOverlay(int overlayId, int timeout, int layer, QString message){
    Q_UNUSED(message)
    qDebug() << "Display overlay - " << overlayId;
    QQuickItem *overlayScreen = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("overlayContainer");
    if(!overlayScreen){
        qDebug() << "OverlayScreen null";
        return;
    }

    if(layer > BACKGROUND)
        overlayScreen->setProperty("z", QVariant::fromValue(layer));

    overlayScreen->setProperty("source", QVariant::fromValue(mapScreen.value(overlayId)));
    QObject *overlay = qvariant_cast<QObject*>(overlayScreen->property("item"));
    overlay->setProperty("timeout", QVariant::fromValue(timeout));
    if(!message.isEmpty())
        overlay->setProperty("message", QVariant::fromValue(message));
}

void ManagerEvent::hideOverlay(){
    QQuickItem *overlayScreen = m_engine.rootObjects().at(0)->findChild<QQuickItem*>("overlayContainer");
    if(!overlayScreen) {
        qDebug() << "OverlayScreen null";
        return;
    }

    overlayScreen->setProperty("source", "");
}

void ManagerEvent::hmiHandle(QString objectName, int EnumID, QString param){
    switch (EnumID) {
    case EnumID::HMI_HOME_SCREEN:
    {
        showScreen(ICS_HOME);
        break;
    }
    case EnumID::HMI_CONNECTION_PORTCOM_SCREEN:
    {
        showScreen(ICS_CONNECTION_PORTCOM);
        break;
    }
    case EnumID::HMI_CONNECTION_NETWORK_SCREEN:
    {
        showScreen(ICS_CONNECTION_NETWORK);
        break;
    }
    case EnumID::HMI_DATA_VIEW_SCREEN:
    {
        showScreen(ICS_DATA_VIEW);
        break;
    }
    case EnumID::HMI_HIDE_POPUP:
    {
        hideOverlay();
        break;
    }
    case EnumID::HMI_CONNECTED_POPUP:
    {
        showOverlay(ICS_CONNECT_POPUP, 3000);
        break;
    }
    case EnumID::HMI_DISCONNECTED_POPUP:
    {
        showOverlay(ICS_DISCONNECT_POPUP, 3000);
        break;
    }
    default:
        break;
    }
}
