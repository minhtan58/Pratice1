import QtQuick 2.0
import DataEnum 1.0

Item {
    id: homeScreen
    objectName: "scr_home"
    anchors.fill: parent

    Image {
        id: diagram_icon
        x: 15
        y: 8
        width: 180
        height: 180
        source: mousre_audio.containsMouse ? "qrc:/resources/images/icon_diagram_pressed.png" : "qrc:/resources/images/icon_diagram.png"

        MouseArea {
            id: mousre_audio
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", DataEnum.HMI_BUTTON_AUDIO, "")
        }
    }

    Image {
        id: setting_icon
        x: 211
        y: 8
        width: 180
        height: 180

        source: mousre_setting.containsMouse ? "qrc:/resources/images/icon_connection_pressed.png" : "qrc:/resources/images/icon_connection.png"

        MouseArea {
            id: mousre_setting
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", DataEnum.HMI_BUTTON_SETTING, "")
        }
    }

    Image {
        id: climate_icon
        x: 407
        y: 8
        width: 180
        height: 180

        source: mousre_climate.containsMouse ? "qrc:/resources/images/icon_climate_pressed.png" : "qrc:/resources/images/icon_climate.png"

        MouseArea {
            id: mousre_climate
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", DataEnum.HMI_BUTTON_CLIMATE, "")
        }
    }

    Image {
        id: data_icon
        x: 603
        y: 8
        width: 180
        height: 180

        source: mousre_data.containsMouse ? "qrc:/resources/images/icon_data_pressed.png" : "qrc:/resources/images/icon_data.png"

        MouseArea {
            id: mousre_data
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", DataEnum.HMI_BUTTON_DATA, "")
        }
    }

    Image {
        id: network_icon
        x: 8
        y: 193
        width: 180
        height: 180

        source: mousre_network.containsMouse ? "qrc:/resources/images/icon_network_pressed.png" : "qrc:/resources/images/icon_network.png"

        MouseArea {
            id: mousre_network
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", DataEnum.HMI_BUTTON_NETWORK, "")
        }
    }
}
