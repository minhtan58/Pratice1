import QtQuick 2.0
import EventID 1.0

Item {
    Row {
        spacing: 20

        Rectangle {
            id: working_icon
            x:300
            //y:100
            width: 80
            height: 80
            color: "lightBlue"
            border.color: "black"
            Text {
                text: qsTr("Working")
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: UIBridge.hmiEvent(EventID.Working_Screen,"")
            }
        }
        Rectangle {
            id: connection_icon
            x:100
            //y:100
            width: 80
            height: 80
            color: "lightBlue"
            border.color: "black"
            Text {
                text: qsTr("Connection")
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked:
                {

                    UIBridge.hmiEvent(EventID.Connetion_Screen,"")
                    //CLient.connectingToHost()
                }
            }
        }
    }
}
