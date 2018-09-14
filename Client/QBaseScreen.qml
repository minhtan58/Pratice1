import QtQuick 2.0
import EventID 1.0

Item {
    id: id_root
    width: 1080
    height: 1080
    Rectangle {
        id: back_home
        width: 50
        height: 30
        color: "lightsteelblue"
        border.color: "black"
        x: 5
        Text {text: qsTr("Back");anchors.centerIn: parent}

    }
    MouseArea {
        anchors.fill: back_home
        onClicked: UIBridge.hmiEvent(EventID.Home_Screen,"")
    }
}
