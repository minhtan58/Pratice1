#ifndef ENUM_H
#define ENUM_H

#include <QObject>

class EventID: public QObject
{
    Q_OBJECT
    Q_ENUMS(_HMIEvent)
public:
     typedef enum _HMIEvent{
        ics_home,
        ics_connection_portcom,
        ics_connection_internet,
    }HMIEvent;
};

#endif // ENUM_H
