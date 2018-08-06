#ifndef DEFINES_H
#define DEFINES_H
#include <QDateTime>
#include <QThread>

//#define HLOG(msg, args...)      qDebug("[%s][Thread-%d][%s] " msg, QDateTime::currentDateTime().toString("HH:mm:ss:zzz").toStdString().c_str(), std::this_thread::get_id(), __PRETTY_FUNCTION__, ##args)
#define HLOG(msg, args...)      qDebug("[%s][%s] " msg, QDateTime::currentDateTime().toString("HH:mm:ss:zzz").toStdString().c_str(), __PRETTY_FUNCTION__, ##args)
#endif // DEFINES_H
