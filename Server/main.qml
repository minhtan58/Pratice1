import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1080
    height: 1080
    title: qsTr("Server")

    Text {
        id: connection_screen
        text: qsTr("Server Status")
        font.bold: true
        font.family: "Time New Roman"
        font.pixelSize: 18
        x: 500
        y: 50
    }
    Column {
        spacing: 10
        x: 600
        y: 100
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

    }
    Rectangle {
        id: connect_to_server_button
        x: 800
        y: 200
        width: 70
        height: 20
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Listen")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Server.startServer();
                show_data.text = Server.readData();
            }
        }
    }
    Rectangle {
        id: receive_data
        width: 450
        height: 500
        border.color: "black"
        x:100
        y:100
        TextEdit {
            id: show_data
            text: Server.message
            anchors.fill: parent
        }
    }
}










