#include "status.h"

Status::Status(QObject *parent) : QObject(parent)
{}

QString Status::message() const
{
    return m_message;
}


//void Status::readData(QString data)
//{
//    QString data1 = data;
//    setMessage(data1);
//}

void Status::setMessage(const QString &m)
{
        if (m_message == m)
            return;
        m_message = m;
        emit messageChanged();
}

