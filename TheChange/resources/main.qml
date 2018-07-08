import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 480
    //title: qsTr("Hello World")

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }
    Item {
        id: screenArea
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        Rectangle {
            id: border
            anchors.fill: parent
            border.color: "#006400"
            border.width: 10
        }
        Image {
            id: background
            source: "qrc:/resources/images/background.png"
        }

        Loader {
            id: mainScreen
            objectName: "mainScreen"
            x: 0
            y: 0
            z: 0
            width: parent.width
            height: parent.width
        }
    }
}
