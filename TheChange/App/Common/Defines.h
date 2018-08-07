#ifndef DEFINES_H
#define DEFINES_H

#include <QDateTime>
#include <QThread>
#include <thread>

#define HLOG(msg, args...)      qDebug("[%s][Thread-%d][%s] " msg, QDateTime::currentDateTime().toString("HH:mm:ss:zzz").toStdString().c_str(), std::this_thread::get_id(), __PRETTY_FUNCTION__, ##args)

#define HLOG_THREAD             qDebug()    << "[" << QThread::currentThreadId() << "][" \
                                            << Q_FUNC_INFO << "]"
#endif // DEFINES_H
