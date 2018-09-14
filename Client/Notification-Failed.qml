import QtQuick 2.0

Item {
    width: 100
    height: 100


    property int timeout: 1000

        Rectangle {
            id: loginFailed
            width: 100
            height: 100
            x: 50
            z: 1
            border.color: "black"
            Text {
                anchors.centerIn: parent
                text: qsTr("Login Failed!")
            }
        }
        //        Rectangle {
        //            id: loginSuccess
        //            width: 100
        //            height: 100
        //            x: 50
        //            z: 1
        //            border.color: "black"
        //            Text {
        //                anchors.centerIn: parent
        //                text: qsTr("Login Success!")
        //            }
        //        }
        Timer {
            id: time_out
            interval: timeout
            repeat: false
            onTriggered: UIBridge.hmiEvent(5)
        }
        Component.onCompleted: {
            time_out.start()
        }
}

