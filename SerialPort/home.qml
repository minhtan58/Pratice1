import QtQuick 1.1

Item {
    id: grpServer
    x: 100
    y: 50
    Text {
        x: 0
        y: 0
        width: 100
        height: 40
        text: "Host IP:"
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 20
        wrapMode: Text.Wrap
    }

    TextInput {
        id: settings_network_server_ip
        objectName: "settings_network_server_ip"
        x: 100
        y: 0
        width: 200
        height: 40
    }

    Text {
        x: 0
        y: 50
        width: 100
        height: 40
        text: "Port:"
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 20
        wrapMode: Text.Wrap
    }
}
