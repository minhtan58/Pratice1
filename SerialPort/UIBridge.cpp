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

void UIBridge::sendEvent(QString objectName, int EnumID, QString param){
    emit hmiEvent(objectName, EnumID, param);
}
