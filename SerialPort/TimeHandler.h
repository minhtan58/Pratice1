#ifndef TIMEHANDLER_H
#define TIMEHANDLER_H

#include <QObject>

class TimeHandler : public QObject
{
    Q_OBJECT
public:
    explicit TimeHandler(QObject *parent = 0);

signals:

public slots:
};

#endif // TIMEHANDLER_H