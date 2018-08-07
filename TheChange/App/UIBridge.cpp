#include "UIBridge.h"

UIBridge *UIBridge::m_uiBridge = nullptr;

UIBridge::UIBridge(QObject *parent) : QObject(parent){
}
UIBridge::~UIBridge(){
}

UIBridge *UIBridge::getInstance(){
    if(m_uiBridge == nullptr)
        m_uiBridge = new UIBridge();
    return m_uiBridge;
}

void UIBridge::getDPData(int dpid){
    return DataManager::getInstance()->getData(dpid);
}

void UIBridge::setDPData(int dpid, QVariant value){
    DataManager::getInstance()->setData(dpID, value.toString());
}

void UIBridge::log(QString msg){
    HLOG_THREAD << msg;
}

void UIBridge::sendEvent(QString objectName, int eventID, Qstring param){
    emit hmiEvent(objectName, eventId, param);
}
