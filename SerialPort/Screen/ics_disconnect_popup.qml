import QtQuick 2.5
import QtQuick.Window 2.2
import EventID 1.0

Item {
    Rectangle{
        x: 100
        y: 100
        width: 100
        height: 50
        color: "green"
        opacity: 0.5
        Text {
            id: disconnected
            text: qsTr("Disconnected")
        }
    }
}
