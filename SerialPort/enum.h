#ifndef ENUM_H
#define ENUM_H

#include <QObject>

class EventID: public QObject
{
    Q_OBJECT
    Q_ENUMS(_HMIEvent)
public:
     typedef enum _HMIEvent{
        ICS_HOME,
        ICS_CONNECTION_PORTCOM,
        ICS_CONNECTION_INTERNET,
    }HMIEvent;
};

#endif // ENUM_H
