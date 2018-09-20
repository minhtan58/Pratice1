import QtQuick 2.5
import QtQuick.Window 2.2
import EnumID 1.0

Window {
    visible: true
    width: 820
    height: 460

    Item {
        id: screenArea
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        Image {
            id: name
            source: "qrc:/Images/background.jpg"
            z: EnumID.BACKGROUND
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
