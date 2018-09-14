import QtQuick 2.5
import QtQuick.Window 2.2
import EventID 1.0

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
            onClicked: UIBridge.hmiEvent(EventID.ics_home,"")
        }
    }

    Text {
        text: qsTr("Port")
        x: 100
        y: 100
    }
    Rectangle {
        x: 100
        y: 120
        width: 300
        height: 25
        border.color: "black"
        TextInput {
            id: port_to_connect
            objectName: "port_to_connect"
            anchors.left: parent.left
            width: 250
            height: 25
        }
    }

    Rectangle {
        id: connect_to_server_button
        x: 750
        y: 250
        width: 70
        height: 20
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Connect")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                MySerialPort.openSerialPort(port_to_connect.text)
            }
        }
    }

    Rectangle {
        id: disconnect_to_server_button
        x: 850
        y: 250
        width: 70
        height: 20
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Disconnect")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                MySerialPort.closeSerialPort();
                //show_notification.text = "Stop Connecting to " + UIBridge.getIPAddress()
            }
        }
    }
}


