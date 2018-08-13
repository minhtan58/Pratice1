import QtQuick 2.0
import DataEnum 1.0

Item{
    id: scr_update_data_fail
    property alias timeout: value.interval
    property alias message: textContent.text
    x: 200
    y: 120
    width: 800
    height: 480

    Timer{
        id:value
        repeat: false
        onTriggered: UIBridge.hmiEvent(this.objectName, DataEnum.HMI_REQUEST_HIDE_POPUP, "")
    }

    Rectangle{
        anchors.fill: parent
        color: "#000000"
        opacity: 0.5
    }
    Rectangle {
        id: qnBgr
        width: 400
        height: 100
        anchors.centerIn: parent
        color: "#315b7d"
        opacity: 0.95
    }
    Text {
        id: textContent
        anchors.fill: qnBgr
        text: "Save Successful"
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 25
        wrapMode: Text.Wrap
    }

    MouseArea {
        anchors.fill: parent
        onClicked: UIBridge.hmiEvent(this.objectName, DataEnum.HMI_REQUEST_HIDE_POPUP, "")
    }
    Component.onCompleted: {
        tim.start()
    }
}
