#include "TaskbarAdapterr.h"

TaskbarAdapter::TaskbarAdapter(QQuickItem *container, QObject *parent) : QObject(parent)
{
    m_taskbarContainer = container;
    m_taskbarView = qvariant_cast<QObject*>(m_taskbarContainer->property("item"));
}

void TaskbarAdapter::initAppData()
{

}

void TaskbarAdapter::updateAppData(int dpid)
{

}
