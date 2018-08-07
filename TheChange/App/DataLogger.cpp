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
    m_threadHatndler = new ThreadHandler(this);


}

void DataLogger::showScreen(int screenId){
    qDebug()    << "[" << QThread::currentThreadId() << "][" << Q_FUNC_INFO << "]";

}
