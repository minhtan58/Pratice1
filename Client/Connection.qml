import QtQuick 2.0
import EventID 1.0
import QtQml.Models 2.2

QBaseScreen {
    //property string mytext: ""
    Text {
        id: connection_screen
        text: qsTr("TCP Client")
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
            text: qsTr("IP Address")
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
                id: ip_addess
                objectName: "ip_addess"
                anchors.left: parent.left
                width: 250
                height: 25
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
            onClicked:
            {
                if(Client.connectedToHost() === true){
                    UIBridge.setIPAddress(ip_addess.text);
                    show_notification.text = "Connect to " + UIBridge.getIPAddress() +" success! \n"
                    //UIBridge.hmiEvent(EventID.Connect_Success_Notification);

                    //show_notification.text = Server.receiveData();
                }
                else {
                    show_notification.text = "Connect to " + UIBridge.getIPAddress() + " failed! \n"
                    //UIBridge.hmiEvent(EventID.Connect_Failed_Notification);
                }
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
                Client.disConnect();
                show_notification.text = "Stop Connecting to " + UIBridge.getIPAddress()
                //UIBridge.hmiEvent(EventID.Stop_Connect_Notification);
            }
        }
    }
    Text {
        id:status
        text: qsTr("Receive/send data")
        x: 200
        y: 180
    }

    Rectangle {
        //property string mytext: ""
        id: notification_Connect
        width: 450
        height: 500
        border.color: "black"
        x:200
        y:200
        Text {
            id: show_notification
            text: {
                Status.message
            }
        }
    }
}








