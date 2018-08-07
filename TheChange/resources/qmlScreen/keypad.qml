import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import "qrc:/Assets/Qml/Audio/js/DCVAudioFavorite.js" as DCVAudioFavorite

Item {
    id: dyn_am_fm_key_pad_widget
    property string textBoxValue: "";
    property int    textBoxMaxLengh: 19;
    property bool isFM: true
    property string enteredFrequency: ""
    property string validKey
    property int favoriteId: 0
    property string objectId: ""
    property string currentFrequency: ""
    onEnteredFrequencyChanged: {
        UIBridge.log("AMFM KEYPAD enteredFrequency" + enteredFrequency);
        if (enteredFrequency == "" )
            dyn_am_currentstationinfostatus_frequency.text = UIBridge.getStringById("ui_enter_station");
        else
            dyn_am_currentstationinfostatus_frequency.text = enteredFrequency;

        AudioInfo.onAMFMValidNumberChanged(isFM, enteredFrequency);
    }
    onFavoriteIdChanged: {
        if (favoriteId === 0)
            img_favorite.source = UIBridge.getImageSourceByName("favorite_inactive");
        else
            img_favorite.source  = UIBridge.getImageSourceByName("favorite_active");
    }
    Component.onCompleted: {
        if (favoriteId === 0)
            img_favorite.source = UIBridge.getImageSourceByName("favorite_inactive");
        else
            img_favorite.source  = UIBridge.getImageSourceByName("favorite_active");

        AudioInfo.onAMFMValidNumberChanged(isFM, enteredFrequency);
    }
    function sendEventToIPC(pressedKey) {
        var _param = "";
        if (pressedKey === "-1") {
            var removedCount = 1;
            if (enteredFrequency.charAt(enteredFrequency.length - 1) === '.') {
                removedCount = 2;
            }
            _param = enteredFrequency.substring(0, enteredFrequency.length - removedCount);
        } else if (pressedKey === "-2"){
            enteredFrequency = "";
        } else {
            _param = enteredFrequency + pressedKey;
        }
        enteredFrequency = _param;
        UIBridge.hmiEvent("amfm_direct_tune_keypad", "evG_Touch_Chime()");
    }

    Connections {
        target: AudioInfo
        onCurrentAMFMValidNumberChanged: {
            validKey = number;
            UIBridge.log("AMFM KEYPAD valid key:" + number + "|");
            if(validKey.trim() === "") {
                if (isFM) {
                    // when entered same frequency with currentFrequency, MW do not handle
                    // if(parseFloat(enteredFrequency) * 100 === parseInt(AudioInfo.currentFMStationFrequency())) {
                    if(enteredFrequency === AudioInfo.currentFMStationFrequency()) {
                        enteredFrequency = "";
                    }
                    else { // when entered new frequency -> tune to that one
                        var fmFreq; // Math.floor(parseFloat(enteredFrequency ) * 100);!!!
                        if(enteredFrequency.indexOf(".") >= 0) {
                            fmFreq = parseInt(enteredFrequency.replace(".","")) * 10;
                        } else {
                            fmFreq = enteredFrequency * 100;
                        }
                        UIBridge.hmiEvent("AMFMKeypad", "evG_FM_DT_Key_Press_No_Sound(" + fmFreq + ")");
                    }
                } else {
                    // when entered same frequency with currentFrequency, MW do not handle
                    if(enteredFrequency === AudioInfo.currentAMStationFrequency()) {
                        enteredFrequency = "";
                    }
                    else { // when entered new frequency -> tune to that one
                        UIBridge.hmiEvent("AMFMKeypad", "evG_AM_DT_Key_Press_No_Sound(" + enteredFrequency + ")");
                    }
                }
            }
        }
        onAddDotToCurrentFMFreq: {
            enteredFrequency += ".";
        }
    }

    Image {
        id: img_keypad_input_bg
        x: 99
        y: 110
        width: 299
        height: 50
        opacity: 100
        source: UIBridge.getImageSourceByName("keypad_input_bg")
    }
    Text {
        id: dyn_am_currentstationinfostatus_frequency
        x: 99
        y: 116
        width: 243
        height: 38
        text: UIBridge.getStringById("ui_enter_station")
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 28
        font.family: I3LFontManager.GMSansUIRegular
        property bool isEnterStationText: text === UIBridge.getStringById("ui_enter_station")
        color: isEnterStationText ? "#878787" : "#ffffff"
        opacity: 100
        maximumLineCount: 1
    }
    Image {
        id: img_favorite
        x: 14
        y: 100
        width: 70
        height: 68
        opacity: 100
        source: (favoriteId === 0) ? UIBridge.getImageSourceByName("favorite_inactive") : UIBridge.getImageSourceByName("favorite_active")
        MouseArea{
            id: favorite_active_mouse_area
            anchors.fill: parent

            onClicked: {
                var _eventCallback = "";
                UIBridge.log("AMFM KEYPAD FAV:" + (isFM) + " | freq: " + currentFrequency
                             + " | favID:" + favoriteId + " | objID:" + objectId);
                if(favoriteId === 0) {
                    if (isFM) {
                        _eventCallback = DCVAudioFavorite.composeAddFavEventCallback(favoriteId,
                                                                                     AudioInfo.currentFMStationLabel(),
                                                                                     AudioInfo.currentFMStationLabel(),
                                                                                     objectId,
                                                                                     DCVAudioFavorite.eLGFavoriteType.LGFT_FM_FREQUENCY);
                    } else {
                        _eventCallback = DCVAudioFavorite.composeAddFavEventCallback(favoriteId,
                                                                                     currentFrequency,
                                                                                     currentFrequency,
                                                                                     objectId,
                                                                                     DCVAudioFavorite.eLGFavoriteType.LGFT_AM_FREQUENCY);
                    }
                } else {
                    if (isFM) {
                        _eventCallback = DCVAudioFavorite.composeRemoveFavoriteByStar(0,
                                                                                     DCVAudioFavorite.eLGFavoriteType.LGFT_FM_FREQUENCY,
                                                                                     objectId,
                                                                                     AudioInfo.currentFMStationLabel());
                    } else {
                        _eventCallback = DCVAudioFavorite.composeRemoveFavoriteByStar(0,
                                                                                      DCVAudioFavorite.eLGFavoriteType.LGFT_AM_FREQUENCY,
                                                                                      objectId,
                                                                                      currentFrequency);
                    }
                }
                if (_eventCallback != "") {
                    UIBridge.hmiEvent(parent.objectName, _eventCallback);
                }
            }
        }
    }
    //    Image {
    //        id: img_keypad_go_btn_selector
    //        x: 13
    //        y: 304
    //        width: 69
    //        height: 120
    //        source: UIBridge.getImageSourceByName("go_button_normal")
    //        opacity: dyn_am_currentstationinfostatus_frequency.text.length == 0 ? 0.6 : 1
    //        MouseArea {
    //            anchors.fill: parent
    //            enabled: dyn_am_currentstationinfostatus_frequency.text.length > 0
    //            onPressed: parent.source = UIBridge.getImageSourceByName("go_button_highlight")
    //            onReleased: parent.source = UIBridge.getImageSourceByName("go_button_normal")
    //            onClicked: {
    //                sendEventToIPC("");
    //            }
    //        }
    //    }
    //    Text {
    //        id: ui_go
    //        text: ""
    //        x: 13
    //        y: 351
    //        width: 69
    //        height: 32
    //        horizontalAlignment: Text.AlignHCenter
    //        verticalAlignment: Text.AlignVCenter
    //        font.pixelSize: 23
    //        font.family: I3LFontManager.GMSansUILight
    //        color: "#ffffff"
    //        opacity: 100
    //    }
    Image {
        id: img_keypad_delete_selector
        x: 341
        y: 106
        width: 56
        height: 58
        opacity: dyn_am_currentstationinfostatus_frequency.isEnterStationText ? 0.6 : 1
        source: UIBridge.getImageSourceByName("delete_normal")
        MouseArea {
            anchors.fill: parent
            enabled: !dyn_am_currentstationinfostatus_frequency.isEnterStationText
            onPressed: parent.source = UIBridge.getImageSourceByName("delete_highlight")
            onReleased: parent.source = UIBridge.getImageSourceByName("delete_normal")
            onClicked: {
                sendEventToIPC("-1");
            }
            onPressAndHold: {
                sendEventToIPC("-2");
            }
        }
    }
    Text {
        id: ui_1_short
        text: "1"
        x: 97
        y: 175
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("1") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector
        x: 97
        y: 175
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("1") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false

        MouseArea {
            id: mousearea1
            enabled: validKey.indexOf("1") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector.isPressing = true;
            onReleased: keypad_button_selector.isPressing = false;
            onCanceled: keypad_button_selector.isPressing = false;
            onClicked: {
                sendEventToIPC("1");
            }
        }
    }
    Text {
        id: ui_2_short
        text: "2"
        x: 198
        y: 175
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("2") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_1
        x: 198
        y: 175
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("2") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea_2
            enabled: validKey.indexOf("2") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_1.isPressing = true;
            onReleased: keypad_button_selector_1.isPressing = false;
            onCanceled: keypad_button_selector_1.isPressing = false;
            onClicked: {
                sendEventToIPC("2");
            }
        }
    }
    Text {
        id: ui_3_short
        text: "3"
        x: 299
        y: 175
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("3") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_2
        x: 299
        y: 175
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("3") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea3
            enabled: validKey.indexOf("3") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_2.isPressing = true;
            onReleased: keypad_button_selector_2.isPressing = false;
            onCanceled: keypad_button_selector_2.isPressing = false;
            onClicked: {
                sendEventToIPC("3");
            }
        }
    }
    Text {
        id: ui_4_short
        text: "4"
        x: 97
        y: 239
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("4") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_3
        x: 97
        y: 239
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("4") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea4
            enabled: validKey.indexOf("4") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_3.isPressing = true;
            onReleased: keypad_button_selector_3.isPressing = false;
            onCanceled: keypad_button_selector_3.isPressing = false;
            onClicked: {
                sendEventToIPC("4");
            }
        }
    }
    Text {
        id: ui_5_short
        text: "5"
        x: 198
        y: 239
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("5") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_4
        x: 198
        y: 239
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("5") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea5
            enabled: validKey.indexOf("5") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_4.isPressing = true;
            onReleased: keypad_button_selector_4.isPressing = false;
            onCanceled: keypad_button_selector_4.isPressing = false;
            onClicked: {
                sendEventToIPC("5");
            }
        }
    }
    Text {
        id: ui_6_short
        text: "6"
        x: 299
        y: 239
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("6") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_5
        x: 299
        y: 239
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("6") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea6
            anchors.fill: parent
            enabled: validKey.indexOf("6") >= 0
            onPressed: keypad_button_selector_5.isPressing = true;
            onReleased: keypad_button_selector_5.isPressing = false;
            onCanceled: keypad_button_selector_5.isPressing = false;
            onClicked: {
                sendEventToIPC("6");
            }
        }
    }
    Text {
        id: ui_7_short
        text: "7"
        x: 97
        y: 303
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("7") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_6
        x: 97
        y: 303
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("7") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea7
            enabled: validKey.indexOf("7") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_6.isPressing = true;
            onReleased: keypad_button_selector_6.isPressing = false;
            onCanceled: keypad_button_selector_6.isPressing = false;
            onClicked: {
                sendEventToIPC("7");
            }
        }
    }
    Text {
        id: ui_8_short
        text: "8"
        x: 198
        y: 303
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("8") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_7
        x: 198
        y: 303
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("8") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea8
            enabled: validKey.indexOf("8") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_7.isPressing = true;
            onReleased: keypad_button_selector_7.isPressing = false;
            onCanceled: keypad_button_selector_7.isPressing = false;
            onClicked: {
                sendEventToIPC("8");
            }
        }
    }
    Text {
        id: ui_9_short
        text: "9"
        x: 299
        y: 303
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("9") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_8
        x: 299
        y: 303
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("9") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea9
            enabled: validKey.indexOf("9") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_8.isPressing = true;
            onReleased: keypad_button_selector_8.isPressing = false;
            onCanceled: keypad_button_selector_8.isPressing = false;
            onClicked: {
                sendEventToIPC("9");
            }
        }
    }
    Text {
        id: ui_0_short
        text: "0"
        x: 198
        y: 367
        z: 1
        width: 99
        height: 62
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 40
        font.family: I3LFontManager.GMSansUILight
        color: (validKey.indexOf("0") >= 0) ? "#ffffff" : "#878787"
        opacity: 100
    }
    Image {
        id: keypad_button_selector_9
        x: 198
        y: 367
        width: 99
        height: 62
        source: isPressing ? UIBridge.getImageSourceByName("short_button_highlight_big") :
                             (validKey.indexOf("0") >= 0 ? UIBridge.getImageSourceByName("short_button_normal_big") : UIBridge.getImageSourceByName("short_button_disabled_big"))

        property bool isPressing: false
        MouseArea {
            id: mousearea0
            enabled: validKey.indexOf("0") >= 0
            anchors.fill: parent
            onPressed: keypad_button_selector_9.isPressing = true;
            onReleased: keypad_button_selector_9.isPressing = false;
            onCanceled: keypad_button_selector_9.isPressing = false;
            onClicked: {
                sendEventToIPC("0");
            }
        }
    }

    //NOTE: The next three elements are actually outside the widget
    Text {
        id: dyn_fm_hdmetadatastatus_psd_hdartistname
        x: 443
        y: 211
        width: 310
        height: 38
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 28
        font.family: I3LFontManager.GMSansUILight
        color: "#ffffff"
        opacity: 100
    }
    Text {
        id: dyn_fm_hdmetadatastatus_psd_hdsongtitle
        x: 443
        y: 256
        width: 310
        height: 38
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 28
        font.family: I3LFontManager.GMSansUILight
        color: "#ffffff"
        opacity: 100
    }
}
