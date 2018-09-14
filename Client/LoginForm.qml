import QtQuick 2.0
import EventID 1.0

    Item {

        Rectangle {
            id: user
            width: 200
            height: 40
            x:400
            y:150
            border.color: "black"
            TextInput {
                id: user1
                width: 200
                height: 40
                text: "anhtu"
                opacity: 0.5
                font.family: "Ubuntu"
                font.pointSize: 18
                color: "black"
                wrapMode: TextInput.WrapAnywhere
                clip: true

            }
        }
        Rectangle {
            id: login_push
            width: 100
            height: 60
            x:450
            y:220
            border.color: "black"
            Text {
                anchors.centerIn: parent
                text: qsTr("LOGIN")
                font.family: "Ubuntu"
                font.pointSize: 16
            }

            MouseArea {
                id: move_home
                anchors.fill: parent
                onClicked:
                {
                    if(user1.text != "anhtu")
                    {
                        UIBridge.hmiEvent(EventID.Notification_Failed_Screen,"");
                    }

                    else
                    {
                        UIBridge.hmiEvent(EventID.Notification_Success_Screen,"");
                        UIBridge.hmiEvent(EventID.Home_Screen,"");
                    }
                }
            }
        }
    }
