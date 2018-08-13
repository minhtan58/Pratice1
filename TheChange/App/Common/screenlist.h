#ifndef SCREENLIST_H
#define SCREENLIST_H

#include <QHash>

enum LeverShow{
    Z_BACKGROUND = -1,
    Z_APPCONTAINER,
    Z_TOPBAR,
    Z_KEYBOARD,
    Z_OVERLAY,
    Z_SPLASH
};

enum ScreenID {
    ICS_HOME = 0x1000,
    ICS_AUDIO,
    ICS_SETTING,
    ICS_CLIMATE,
    ICS_DATA,
    ICS_NETWORK,

    //Overlay screen
    ICS_UPDATE_DATA_COMPLETE = 0x2000,
    ICS_UPDATE_DATA_FAIL

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
