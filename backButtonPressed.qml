import QtQuick 2.15
import QtQuick.Controls 2.15

Popup {
    id: backButtonPressPopup
    width: parent.width * 0.9
    height: parent.height * 0.2
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    modal: true
    focus: true
    closePolicy: Popup.NoAutoClose

    Component.onCompleted: {
            backButtonPressPopup.forceActiveFocus()
        }

    signal closeRequested()

    background: Rectangle {
        color: "#1a3157"
        radius: 15
    }

    contentItem: Column {
        spacing: 20
        anchors.centerIn: parent

        Text {
            text: "Oyun Durduruldu!"
            color: "white"
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            topPadding: 20

            Button {
                id: mainMenuButton
                text: "Ana Menü"
                font.pixelSize: 20
                background: Rectangle {
                    color: "white"
                    radius: 10
                    height: 80
                    width: 150
                    border.color: "black"
                    border.width: 2
                }
                contentItem: Text {
                    text: mainMenuButton.text
                    font: mainMenuButton.font
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
                onClicked: {
                    sudokuTable.atOpenMainMenuBackPressedKey();
                    backButtonPressPopup.closeRequested();
                }
            }

            Button {
                id: gameBackButton
                text: "Oyuna Dön"
                font.pixelSize: 20
                background: Rectangle {
                    color: "white"
                    radius: 10
                    height: 80
                    width: 150
                    border.color: "black"
                    border.width: 2
                }
                contentItem: Text {
                    text: gameBackButton.text
                    font: gameBackButton.font
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
                onClicked: {
                    backButtonPressPopup.closeRequested();
                }
            }
        }
    }

    Keys.onPressed: (event) => {
        if (event.key === Qt.Key_Back) {
            event.accepted = true;
            backButtonPressPopup.closeRequested();
        }
    }
}
