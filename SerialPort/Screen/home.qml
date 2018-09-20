import QtQuick 2.0
import EnumID 1.0

Item {
    Rectangle {
        id: working_icon
        x:100
        y:100
        width: 80
        height: 80
        color: "lightBlue"
        border.color: "black"
        Text {
            text: qsTr("PortCom")
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent("", EnumID.HMI_CONNECTION_PORTCOM_SCREEN, "")
            }
        }
    }

    Rectangle {
        id: connection_icon
        x: 200
        y: 100
        width: 80
        height: 80
        color: "lightBlue"
        border.color: "black"
        Text {
            text: qsTr("Internet")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent("", EnumID.HMI_CONNECTION_NETWORK_SCREEN, "")
            }
        }
    }

    Rectangle {
        id: dada_view
        x: 300
        y: 100
        width: 80
        height: 80
        color: "lightBlue"
        border.color: "black"
        Text {
            text: qsTr("Dataview")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent("", EnumID.HMI_DATA_VIEW_SCREEN, "")
            }
        }
    }

}
