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
            onClicked: UIBridge.hmiEvent(EventID.ICS_HOME,"")
        }
    }

    Text {
        text: qsTr("Port")
        x: 50
        y: 40
    }
    Rectangle {
        x: 50
        y: 60
        width: 50
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
        id: connect_server_button
        x: 130
        y: 60
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
                MySerialPort.openSerialPort(port_to_connect.text);
                MySerialPort.readData()
                //show_notification.text = "Stop Connecting to " + UIBridge.getIPAddress()
            }
        }
    }

    Rectangle {
        id: disconnect_server_button
        x: 220
        y: 60
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

    Text {
        text: qsTr("Send Data")
        x: 50
        y: 100
    }
    Rectangle {
        x: 50
        y: 120
        width: 200
        height: 25
        border.color: "black"
        TextInput {
            id: data_send
            objectName: "data_send"
            anchors.left: parent.left
            width: 250
            height: 25
        }
    }

    Rectangle {
        id: send_button
        x: 260
        y: 120
        width: 70
        height: 20
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Send")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                MySerialPort.writeData(data_send.text);
                //show_notification.text = "Stop Connecting to " + UIBridge.getIPAddress()
            }
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

    Text {
        id:status
        text: qsTr("Receive/send data")
        x: 50
        y: 160
    }

    Rectangle {
        //property string mytext: ""
        id: notification_Connect
        width: 300
        height: 150
        border.color: "black"
        x:50
        y:180
        Text {
            id: show_notification
            text: {
                Status.message
            }
        }
    }
}

