import QtQuick 2.0
import QtQml.Models 2.2
import EventID 1.0


QBaseScreen {
    Text {
        id: get_data
        text: qsTr("Nhập Thông Số Chất Lượng ")
        //anchors.centerIn: parent
        font.bold: true
        font.family: "Tisme New Roman"
        font.pixelSize: 18
        x:500
        y: 50
    }

    Rectangle {
        id: send_data
        width: 50
        height: 50
        color: "lightgreen"
        border.color: "black"
        x:600
        y:400
        Text {
            text: qsTr("Send")
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked:
            {
                //$[TIME,%1][CODE,%2][CO,%3][NO2,%4][PM10,%5][PM25,%6]\r\n

                UIBridge.hmiEvent(EventID.Send_Data_To_Server,
                                  "[TIME,"+ UIBridge.getTime()+ "]" + "[CODE,12345]" + "[CO," + value_of_CO.text +"]" +
                                  "[NO2," + value_of_NO2.text +"]" +
                                  "[PM10," + value_of_PM10.text +"]" +
                                  "[PM2.5," + value_of_PM2_5.text +"]" );


//                Client.sendData("AQI CO = " + value_of_CO.text)
//                Client.sendData("AQI NO2 = " + value_of_NO2.text)
//                Client.sendData("AQI PM10 = " + value_of_PM10.text)
//                Client.sendData("AQI PM2.5 = " + value_of_PM2_5.text)

                Status.message = "Sent To Server: " + UIBridge.getIPAddress() + "\n" +
                        "AQI CO = " + value_of_CO.text + "\n" +
                        "AQI NO2 = " + value_of_NO2.text + "\n" +
                        "AQI PM10 = " + value_of_PM10.text + "\n" +
                        "AQI PM2.5 = " + value_of_PM2_5.text + "\n";
            }
        }
    }
    Column{

        spacing: 10
        x: 100
        y: 100

        Rectangle {
            x: 100
            y: 100
            width: 500
            height: 25
            border.color: "black"
            Text {
                //id: nameCO
                text: qsTr("AQI CO:  ")
                anchors.left: parent.left
            }
            TextInput {
                id: value_of_CO
                anchors.centerIn:parent
                width: 350
                height: 25
            }
        }
        Rectangle {
            x: 100
            y: 100
            width: 500
            height: 25
            border.color: "black"
            Text {
                //id: nameNO2
                text: qsTr("AQI NO2:  ")
                anchors.left: parent.left            }
            TextInput {
                id: value_of_NO2
                anchors.centerIn:parent
                width: 350
                height: 25
            }
        }
        Rectangle {
            x: 100
            y: 100
            width: 500
            height: 25
            border.color: "black"
            Text {
                //id: namePM10
                text: qsTr("AQI PM10:  ")
                anchors.left: parent.left            }
            TextInput {
                id: value_of_PM10
                anchors.centerIn:parent
                width: 350
                height: 25
            }
        }
        Rectangle {
            x: 100
            y: 100
            width: 500
            height: 25
            border.color: "black"
            Text {
                //id: namePM25
                text: qsTr("AQI PM2.5:  ")
                anchors.left: parent.left            }
            TextInput {
                id: value_of_PM2_5
                anchors.centerIn:parent
                width: 350
                height: 25
            }
        }
    }
}


