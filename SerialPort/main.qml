import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 480
    Item {
        id: screenArea
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        Rectangle {
            id: border
            anchors.fill: parent
            border.color: "#006400"
            border.width: 2
        }

        Loader {
            id: screenContainer
            objectName: "screenContainer"
            anchors.fill: parent
        }

        Loader {
            id: overlayContainer
            objectName: "overlayContainer"
            anchors.fill: parent
        }
    }
}
