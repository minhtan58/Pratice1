import QtQuick 2.0
import EventID 1.0

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
                console.log("Bam roi 1")
                UIBridge.hmiEvent(EventID.HMI_CONNECTION_PORTCOM_SCREEN,"")
            }
        }
    }
    Rectangle {
        id: connection_icon
        x:200
        y:100
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
                console.log("Bam roi 2")
                UIBridge.hmiEvent(EventID.HMI_CONNECTION_NETWORK_SCREEN,"")
            }
        }
    }
}
