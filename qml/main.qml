import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    Material.theme: Material.Dark
    Material.accent: Material.Teal

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            id: speedDisplay
            text: "Speed: " + car.currentSpeed
            font.pointSize: 48
            font.bold: true
            color: Material.lightForeground
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            Component.onCompleted: {
                console.log("Initial speed: " + car.currentSpeed)
            }
        }

        Button {
            text: "ACCELERATING"
            font.pointSize: 24
            background: Rectangle {
                color: Material.accent
                radius: 12
            }
            contentItem: Text {
                text: control.text
                color: Material.primaryText
                font.pointSize: control.font.pointSize
                font.bold: true
                anchors.centerIn: parent
            }
            onClicked: car.accSlot()
            width: 200
            height: 60
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: 50
        }
    }
}
