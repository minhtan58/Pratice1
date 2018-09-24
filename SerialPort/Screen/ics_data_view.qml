import QtQuick 2.0
import EnumID 1.0

Item {
    Rectangle {
        id: back_home
        width: 50
        height: 30
        color: "lightsteelblue"
        border.color: "black"
        x: 5
        y: 5
        Text {text: qsTr("Back");anchors.centerIn: parent}
        MouseArea {
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", EnumID.ICS_HOME,"")
        }
    }

    Rectangle {
        id: data_from_portcom
        x: 200
        y: 100
        width: 80
        height: 80
        color: "lightBlue"
        border.color: "black"
        Text {
            id: data_portcom
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: data_from_network
        x: 300
        y: 100
        width: 80
        height: 80
        color: "lightBlue"
        border.color: "black"
        Text {
            id: data_network
            anchors.centerIn: parent
        }
    }
}
