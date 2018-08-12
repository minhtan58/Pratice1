import QtQuick 2.0
import DataEnum 1.0

Item {
    id: settingScreen
    objectName: "scr_setting"
    anchors.fill: parent

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
            onClicked: UIBridge.hmiEvent("", DataEnum.HMI_BUTTON_HOME, "")
        }
    }
}
