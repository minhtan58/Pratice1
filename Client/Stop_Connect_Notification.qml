import QtQuick 2.0
import EventID 1.0


Item {
    width: 200
    height: 200


    property int timeout: 1000

    Rectangle {
        id: loginFailed
        width: 200
        height: 100
        x: 100
        y: 100
        z: 1
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Ngung Ket Noi")
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

