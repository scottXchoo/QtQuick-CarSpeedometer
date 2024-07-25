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

        // 속도 표시 배경
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

        // 속도 표시 변하는 부분
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

        // 현재 차량 속도
        Text {
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -60
            text: car.currentSpeed
            font.pointSize: 120
            color: "#FFFFFF"
        }

        // 속도 단위
        Text {
            anchors.centerIn: parent
            anchors.verticalCenterOffset: 10
            text: "km/h"
            font.pointSize: 24
            color: "#888888"
        }

        // Left Indicator
        Rectangle {
            id: leftIndicator
            width: 50
            height: 20
            color: "yellow"
            opacity: car.isLeftIndicatorOn ? 1 : 0 // visible : car.isLeftIndicatorOn 가능
            anchors {
                left: parent.left
                leftMargin: 20
                top: parent.top
                topMargin: 20
            }

            SequentialAnimation on opacity {
                id: blinkAnimation
                loops: Animation.Infinite
                running: car.isLeftIndicatorOn
                PropertyAnimation {
                    to: 1; duration: 50
                }
                PauseAnimation {
                    duration: 700
                }
                PropertyAnimation {
                    to: 0; duration: 50
                }
            }
        }

        // ACCEL 버튼
        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 70
            anchors.horizontalCenter: parent.horizontalCenter
            width: 160
            height: 60
            color: "#1DB954"
            radius: 20

            Text {
                anchors.centerIn: parent
                text: "ACCELERATE"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: car.handleAccSlot()
            }
        }

        // DECEL 버튼
        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 150
            anchors.horizontalCenter: parent.horizontalCenter
            width: 160
            height: 60
            color: "#1DB954"
            radius: 20

            Text {
                anchors.centerIn: parent
                text: "DECELERATE"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: car.handleDecSlot()
            }
        }

        // Left Indicator 버튼
        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 110
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 90
            width: 60
            height: 60
            color: "#1DB954"
            radius: 20

            Text {
                anchors.centerIn: parent
                text: "LEFT"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: car.handleLeftIndicatorSlot()
            }
        }
    }
}
