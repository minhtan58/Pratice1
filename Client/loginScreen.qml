import QtQuick 2.0

Item {


    Rectangle {
        id: login_push
        width: 60
        height: 60
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("LOGIN")
        }
    }
}
