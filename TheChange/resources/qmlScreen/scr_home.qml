import QtQuick 2.0
import DataEnum 1.0

Item {
    id: homeScreen
    objectName: "scr_home"
    anchors.fill: parent

    Image {
        id: img_bg_main
        property string focusSource: ''
        property string normalSource: UIBridge.getImageSourceByName("bg_main")
        objectName: "img_bg_main"
        width: 800
        height: 480
        source: normalSource
        y: 0
        x: 0

        MouseArea {
            anchors.fill: parent
        }
    }

    Image {
        id: audio_icon
        x: 15
        y: 8
        width: 180
        height: 180
        source: mousre_audio.containsMouse ? "qrc:/resources/audio_icon_active.png" : "qrc:/resources/image/audio_icon_inactive.png"

        MouseArea {
            id: mousre_audio
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", CEMSEnum.HMI_BUTTON_HOME, "")
        }
    }

    Image {
        id: setting_icon
        x: 211
        y: 8
        width: 180
        height: 180

        source: mousre_setting.containsMouse ? "qrc:/resources/icon_setting.png" : "qrc:/resources/image/icon_setting_pressed.png"

        MouseArea {
            id: mousre_setting
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", CEMSEnum.HMI_BUTTON_HOME, "")
        }
    }

    Image {
        id: climate_icon
        x: 407
        y: 8
        width: 180
        height: 180

        source: mousre_climate.containsMouse ? "qrc:/resources/icon_climate.png" : "qrc:/resources/image/icon_climate_pressed.png"

        MouseArea {
            id: mousre_climcate
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", CEMSEnum.HMI_BUTTON_HOME, "")
        }
    }

    Image {
        id: data_icon
        x: 603
        y: 8
        width: 180
        height: 180

        source: mousre_data.containsMouse ? "qrc:/resources/data_icon_active.png" : "qrc:/resources/image/data_icon_inactive.png"

        MouseArea {
            id: mousre_data
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", CEMSEnum.HMI_BUTTON_HOME, "")
        }
    }

    Image {
        id: network_icon
        x: 8
        y: 193
        width: 180
        height: 180

        source: mousre_network.containsMouse ? "qrc:/resources/network_icon_active.png" : "qrc:/resources/image/network_icon_inactive.png"

        MouseArea {
            id: mousre_network
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", CEMSEnum.HMI_BUTTON_HOME, "")
        }
    }
}
