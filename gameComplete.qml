import QtQuick 2.15
import QtQuick.Controls 2.15

Popup {
    id: gameCompletePopup
    width: 300
    height: 200
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    modal: true
    focus: true
    closePolicy: Popup.NoAutoClose
    visible: false

    signal closeRequested()

    background: Rectangle {
        color: "#1a5157"
        radius: 15
    }

    Column {
        spacing: 20
        anchors.centerIn: parent

        Text {
            text: "Tebrikler!"
            color: "white"
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: mainMenuButton
            text: "Ana Menü"
            font.pixelSize: 20
            width: 160
            height: 80
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "white"
                radius: 10
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
                sudokuTable.atOpenMainMenu();
                gameCompletePopup.closeRequested();
            }
        }
    }
}
