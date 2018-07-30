import QtQuick 2.3

Item {
    id: root
    objectName: "dyn_id_sliderbar_widget"

    property string elapseTime: "-:-"
    property string remainingTime: "-:-"

    property int trackTime: 0
    property int progressPercent: 0
    enabled: (elapseTime !== "-:-") && (remainingTime !== "-:-")

    width: parent.width
    height: parent.height
    property bool isEnabledDrag: true

    onElapseTimeChanged: {
        if (!playingMouseArea.pressed || !isEnabledDrag) {
            dyn_elapsedplaytime.text = elapseTime;
        }
    }
    onRemainingTimeChanged: {
        if (!playingMouseArea.pressed || !isEnabledDrag) {
            dyn_remainingplaytime.text = remainingTime;
        }
    }

    onProgressPercentChanged: {
        if (!playingMouseArea.pressed || !isEnabledDrag) {
            displayProgressFillAndScrubberPos(img_timed_progressbar.width * progressPercent / 100);
        }
    }

    function displayProgressFillAndScrubberPos(fillWidth) {
        img_timed_progressbar_fill.width = fillWidth;
        img_scrubber.x = img_timed_progressbar.x + img_timed_progressbar_fill.width - img_scrubber.width/2;
    }

    function convertTimeToDisplay(pTime) {
        //MediaRcvHandler2::convertToHHMMSS
        var hours = 0; var mins = 0; var secs = 0;
        hours = Math.floor(pTime / 3600);
        var rem = Math.floor(pTime % 3600);
        mins = Math.floor(rem / 60);
        secs = Math.floor(rem % 60);
        var time = "";
        if (hours > 0) {
            time = hours + ":";
            if(mins > 9) {
                time += mins + ":";
            } else if(mins > 0) {
                time += "0" + mins + ":";
            } else {
                time += "00:";
            }
        } else {
            if(mins > 0) {
                time += mins + ":";
            } else {
                time += "0:";
            }
        }

        if(secs > 9) {
            time += secs;
        } else if(secs > 0) {
            time += "0" + secs;
        } else {
            time += "00";
        }
        return time;
    }

    function getXPosition(xPst){
        if(xPst < 0){
            xPst = 0;
        }
        else if(xPst > img_timed_progressbar.width ){
            xPst = img_timed_progressbar.width;
        }
        return xPst;
    }

    function changeMouse(xPosition){
        xPosition = getXPosition(xPosition);
        displayProgressFillAndScrubberPos(xPosition);
        return xPosition;
    }

    function displayTimeDrag(xPosition) {
        var totalTime = Math.round(trackTime / 1000); // (ms to s)
        xPosition = getXPosition(xPosition);
        // roung two times to match with number which sent to ipc
        var elapsed = Math.round(Math.round(xPosition * 100 / img_timed_progressbar.width) * totalTime / 100);
        var remaining = totalTime - elapsed;
        dyn_elapsedplaytime.text = convertTimeToDisplay(elapsed);
        dyn_remainingplaytime.text = "-" + convertTimeToDisplay(remaining);
    }

    function caculatePlayPoint(xPosition){
        xPosition = getXPosition(xPosition);
        var playPoint = Math.round(xPosition * 100 / img_timed_progressbar.width);
        return playPoint;
    }

    Text {
        id: dyn_elapsedplaytime
        width: 100
        height: 24
        x: 134
        y: 248
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 19
        horizontalAlignment: Text.AlignRight
        font.family: I3LFontManager.GMSansUIRegular
    }
    Image {
        id: img_timed_progressbar
        x: 240
        y: 258
        width: 288
        height: 6
        source: UIBridge.getImageSourceByName("timed_progress_track_317")
    }
    Image {
        id: img_timed_progressbar_fill
        x: img_timed_progressbar.x
        y: img_timed_progressbar.y
        width: img_timed_progressbar.width * progressPercent / 100
        height: 4
        source: UIBridge.getImageSourceByName("timed_progress_fill")
    }

    MouseArea{
        id: playingMouseArea
        width: img_timed_progressbar.width
        height: 5 * img_timed_progressbar.height
        x: img_timed_progressbar.x
        y: img_timed_progressbar.y - 2*img_timed_progressbar.height
        enabled: isEnabledDrag
        onClicked: {
            changeMouse(mouseX);
        }
        onMouseXChanged: {
            if (pressed) {
                changeMouse(mouseX);
                displayTimeDrag(mouseX);
            }
        }
        onPressed: {
            changeMouse(mouseX);
        }
        onReleased: {
            UIBridge.hmiEvent("dyn_id_sliderbar_widget", "evG_Media_SeekPlayPoint(" + caculatePlayPoint(mouseX) + ")");
        }
    }
    Image {
        id: img_scrubber
        x: img_timed_progressbar.x + img_timed_progressbar_fill.width - img_scrubber.width/2;
        y: 254
        width: 14
        height: 14
        source: UIBridge.getImageSourceByName("scrubber")
    }

    Text {
        id: dyn_remainingplaytime
        x: 533
        y: 248
        width: 100
        height: 24
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 19
        horizontalAlignment: Text.AlignLeft
        font.family: I3LFontManager.GMSansUIRegular
    }
}
