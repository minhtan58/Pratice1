import QtQuick 2.0
import EventID 1.0

Item {
    width: 200
    height: 200


    property int timeout: 1000
    Rectangle {
        id: loginSuccess
        width: 200
        height: 100
//        x: 50
//        y: 50
//        z: 1
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Login Success!")
        }
    }
    Timer {
        id: time_out
        interval: timeout
        repeat: false
        onTriggered: UIBridge.hmiEvent(EventID.None_Screen,"")
    }
    Component.onCompleted: {
        time_out.start()
    }
}
