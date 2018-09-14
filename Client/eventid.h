#ifndef EVENTID_H
#define EVENTID_H

#include <QObject>

class EventID: public QObject
{
    Q_OBJECT
    Q_ENUMS(_HMIEvent)
public:
     typedef enum _HMIEvent{
        Home_Screen,
        Working_Screen,
        Connetion_Screen,
        Notification_Failed_Screen,
        Notification_Success_Screen,
        None_Screen,
        Connect_Failed_Notification,
        Connect_Success_Notification,
        Stop_Connect_Notification,
        Send_Data_To_Server
    }HMIEvent;
};



#endif // EVENTID_H
