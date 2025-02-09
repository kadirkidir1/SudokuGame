pragma ComponentBehavior: Bound

import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root
    anchors.fill: parent
    focus: true

    property real customWidth: parent.width * 0.9
    property real customHeight: parent.height * 0.9

    width: customWidth
    height: customHeight

    property int backButtonPressCount: 0

    Keys.onBackPressed: {
        if (backButtonPressCount === 0) {
            backButtonPressPopupLoader.active = true;
            backButtonPressCount++;
            event.accepted = true;

        } else {
            Qt.quit();
        }
    }

    Loader {
            id: gameOverPopUpLoader
            active: false
            source: "qrc:/gameOverPopUp.qml"
            anchors.fill: parent
            onLoaded: {
                if (item) {
                    item.visible = true;
                    item.closeRequested.connect(function() {
                        gameOverPopUpLoader.active = false;
                    });
                }
            }
        }

    Loader {
        id: backButtonPressPopupLoader
        active: false
        source: "qrc:/backButtonPressed.qml"
        anchors.fill: parent

        onLoaded: {
            item.visible = true;
            item.closeRequested.connect(function() {
                backButtonPressPopupLoader.active = false;
                backButtonPressCount = 0;
            });
        }
    }

    Loader {
        id: gameCompletePopupLoader
        active: false
        source: "qrc:/gameComplete.qml"
        anchors.fill: parent

        onLoaded: {
            item.visible = true;
            item.closeRequested.connect(function() {
                gameCompletePopupLoader.active = false;
                backButtonPressCount = 0;
            });
        }
    }

    Connections {
            target: sudokuTable
            function onShowGameOverPopup() {
                gameOverPopUpLoader.active = true;
            }

            function onGameCompleted() {
                gameCompletePopupLoader.active = true;
            }
        }

    Grid {
        anchors.centerIn: parent
        columns: 9
        rows: 9
        spacing: 0
        width: parent.width * 0.8
        height: parent.height * 0.8
        topPadding: 100

        Repeater {
            model: 81

            Rectangle {
                width: parent.width / 9
                height: width
                color: "white"
                border.color: "black"
                border.width: 1

                required property int index
                property int row: Math.floor(index / 9)
                property int col: index % 9

                Rectangle {
                    width: parent.width
                    height: 3
                    color: "black"
                    visible: row % 3 === 0 && row !== 0
                    anchors.top: parent.top
                }

                Rectangle {
                    width: 3
                    height: parent.height
                    color: "black"
                    visible: col % 3 === 0 && col !== 0
                    anchors.left: parent.left
                }

                Text {
                    anchors.centerIn: parent
                    text: sudokuTable.getGrid[row][col] === 0 ? "" : sudokuTable.getGrid[row][col]
                    font.pixelSize: 20
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        selectedCell.row = row
                        selectedCell.col = col
                    }
                }

                Rectangle {
                    color: (selectedCell.row === row && selectedCell.col === col) ? "#f0f0A0" : "transparent"
                    opacity: (selectedCell.row === row && selectedCell.col === col) ? 0.5 : 1
                    radius: 5
                    anchors.fill: parent
                }
            }
        }
    }

    Column {
        spacing: 10
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        bottomPadding: 50

        Row {
            spacing: 10
            Repeater {
                model: [1, 3, 5, 7, 9]
                delegate: Button {
                    required property int modelData

                    text: modelData.toString()
                    flat: true
                    background: Rectangle { color: "transparent" }
                    onClicked: {
                        root.selectedNumber = modelData
                        sudokuController.sendCellSelected(selectedCell.row, selectedCell.col, selectedNumber)
                    }

                    font.family: "Meiryo"
                    font.pixelSize: 50
                    font.bold: false
                }
            }
        }

        Row {
            spacing: 10
            Repeater {
                model: [2, 4, 6, 8, "C"]
                delegate: Button {
                    required property var modelData

                    text: modelData.toString()
                    flat: true
                    background: Rectangle { color: "transparent" }
                    onClicked: {
                        if (modelData === "C") {
                            root.selectedNumber = 0
                        } else {
                            selectedNumber = modelData
                        }
                        sudokuController.sendCellSelected(selectedCell.row, selectedCell.col, selectedNumber)
                    }

                    font.family: "Meiryo"
                    font.pixelSize: 50
                    font.bold: false
                }
            }
        }
    }

    Row {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20
        padding: 10

        Text {
            text: "Time: " + (Math.floor(root.elapsedTime / 3600)) + ":" + (Math.floor((root.elapsedTime % 3600) / 60)) + ":" + (root.elapsedTime % 60)
            font.pixelSize: 20
            font.bold: true
        }

        Text {
            text: "Errors: " + Math.floor(sudokuTable.m_errorCounter) + "/3"
            font.pixelSize: 20
            font.bold: true
        }
    }

    Timer {
        id: timeTimer
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            root.elapsedTime++
        }
    }

    property int selectedNumber: 0
    property var selectedCell: QtObject { property int row: -1; property int col: -1 ; property int number : -1}
    property int elapsedTime: 0

    QtObject {
        id: sudokuController
        signal cellSelected(int row, int col, int number)

        function sendCellSelected(row, col, number) {
            sudokuTable.cellSelected(row, col, number)
        }
    }
}
