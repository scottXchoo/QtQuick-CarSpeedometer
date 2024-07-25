import QtQuick
import QtQuick.Controls
import QtQuick.Shapes
import QtQuick.Controls.Material

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    color: "white"
    title: "Tesla Model S"

    Material.theme: Material.Dark
    Material.accent: Material.Green

    Rectangle {
        anchors.fill: parent
        color: "#000000"

        Shape {
            anchors.centerIn: parent
            width: 400
            height: 400
            ShapePath {
                strokeColor: "#333333"
                strokeWidth: 10
                fillColor: "transparent"
                capStyle: ShapePath.RoundCap
                startX: 200; startY: 0;
                PathAngleArc {
                    centerX: 200; centerY: 200
                    radiusX: 200; radiusY: 200
                    startAngle: -180
                    sweepAngle: 180
                }
            }
        }

        Shape {
            anchors.centerIn: parent
            width: 400
            height: 400
            ShapePath {
                strokeColor: "#1DB954"
                strokeWidth: 10
                fillColor: "transparent"
                capStyle: ShapePath.RoundCap
                startX: 200; startY: 0;
                PathAngleArc {
                    centerX: 200; centerY: 200
                    radiusX: 200; radiusY: 200
                    startAngle: -180
                    sweepAngle: car.currentSpeed / 200 * 180
                }
            }
        }

        Text {
            anchors.centerIn: parent
            text: car.currentSpeed
            font.pointSize: 120
            color: "#FFFFFF"
        }

        Text {
            anchors.top: parent.top
            anchors.topMargin: 60
            anchors.horizontalCenter: parent.horizontalCenter
            text: "km/h"
            font.pointSize: 24
            color: "#888888"
        }

        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 70
            anchors.horizontalCenter: parent.horizontalCenter
            width: 200
            height: 60
            color: "#1DB954"
            radius: 30

            Text {
                anchors.centerIn: parent
                text: "ACCELERATE"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: car.accSlot()
            }
        }

        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 150
            anchors.horizontalCenter: parent.horizontalCenter
            width: 200
            height: 60
            color: "#1DB954"
            radius: 30

            Text {
                anchors.centerIn: parent
                text: "DECELERATE"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: car.decSlot()
            }
        }
    }
}
