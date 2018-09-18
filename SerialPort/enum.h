#ifndef ENUM_H
#define ENUM_H

#include <QObject>
#include <QHash>

class EventID: public QObject
{
    Q_OBJECT
    Q_ENUMS(_HMIEvent)
public:
     typedef enum _HMIEvent{
        HMI_HOME_SCREEN,
        HMI_CONNECTION_PORTCOM_SCREEN,
        HMI_CONNECTION_NETWORK_SCREEN,
        HMI_HIDE_POPUP,
        HMI_CONNECTED_POPUP,
        HMI_DISCONNECTED_POPUP
    }HMIEvent;
};

enum OverlayZ{
    BACKGROUND = -1,
    SCREENCONTAINER,
    TASKBAR,
    KEYBOARD,
    OVERLAY,
};

enum  ScreenID{
    ICS_HOME = 0x0000,
    ICS_CONNECTION_PORTCOM,
    ICS_CONNECTION_NETWORK,

    ICS_CONNECT_POPUP = 0xA000,
    ICS_DISCONNECT_POPUP
};

const QHash<int, QString> mapScreen = {
    {ICS_HOME,                             "qrc:/Screen/home.qml"                                },
    {ICS_CONNECTION_PORTCOM,               "qrc:/Screen/ics_connection_portcom.qml"              },
    {ICS_CONNECTION_NETWORK,               "qrc:/Screen/ics_connection_network.qml"              },
    {ICS_CONNECT_POPUP,                    "qrc:/Screen/ics_connect_popup.qml"                         },
    {ICS_DISCONNECT_POPUP,                 "qrc:/Screen/ics_disconnect_popup.qml"                         },
};
#endif // ENUM_H
