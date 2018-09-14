import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1080
    height: 1080

    Loader {
        anchors.fill: parent
        objectName: "screenContainer"
    }
    Loader {
        anchors.fill: parent
        objectName: "popupContainer"
        z: 1
    }
}





