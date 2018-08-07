#ifndef SCREENLIST_H
#define SCREENLIST_H

#include <QHash>


enum ScreenID {
    ICS_HOME = 0x0000,
    ICS_AUDIO,
    ICS_SETTING,
    ICS_CLIMATE,
    ICS_DATA,
    ICS_NETWORK
};

const QHash<int, QString> ScreenList = {
    {ICS_HOME,                 "qrc:/resources/qmlScreen/scr_home.qml"       },
    {ICS_AUDIO,                "qrc:/resources/qmlScreen/scr_audio.qml"      },
    {ICS_SETTING,              "qrc:/resources/qmlScreen/scr_setting.qml"    },
    {ICS_CLIMATE,              "qrc:/resources/qmlScreen/scr_climate.qml"    },
    {ICS_DATA,                 "qrc:/resources/qmlScreen/scr_data.qml"       },
    {ICS_NETWORK,              "qrc:/resources/qmlScreen/scr_network.qml"    },
};


#endif // SCREENLIST_H
