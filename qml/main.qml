import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Tesla Model S"

    Rectangle {
        anchors.fill: parent
        color: "#000000"
        focus: true

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
                    sweepAngle: carModel.currentSpeed / 200 * 180
                }
            }
        }

        // 현재 차량 속도
        Text {
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -60
            text: carModel.currentSpeed.toFixed(0)
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
            width: 20
            height: 440
            radius: 20
            color: "yellow"
            opacity: carModel.leftIndicatorOn ? 1 : 0
            anchors {
                left: parent.left
                leftMargin: 20
                top: parent.top
                topMargin: 20
            }

            SequentialAnimation on opacity {
                id: leftIndicatorBlinkAnimation
                loops: Animation.Infinite
                running: carModel.leftIndicatorOn
                PropertyAnimation {
                    to: 1
                    duration: 0
                }
                PauseAnimation {
                    duration: 1000
                }
                PropertyAnimation {
                    to: 0
                    duration: 100
                }
                PauseAnimation {
                    duration: 300
                }
            }
        }

        // Right Indicator
        Rectangle {
            id: rightIndicator
            width: 20
            height: 440
            radius: 20
            color: "yellow"
            opacity: carModel.rightIndicatorOn ? 1 : 0
            anchors {
                right: parent.right
                rightMargin: 20
                top: parent.top
                topMargin: 20
            }

            SequentialAnimation on opacity {
                id: rightIndicatorBlinkAnimation
                loops: Animation.Infinite
                running: carModel.rightIndicatorOn
                PropertyAnimation {
                    to: 1
                    duration: 0
                }
                PauseAnimation {
                    duration: 1000
                }
                PropertyAnimation {
                    to: 0
                    duration: 100
                }
                PauseAnimation {
                    duration: 300
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
                onPressed: carModel.handleAccPressed()
                onReleased: carModel.handleAccReleased()
            }
        }

        // BRAKE 버튼
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
                text: "BRAKE"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onPressed: carModel.handleBrakePressed()
                onReleased: carModel.handleBrakeReleased()
            }
        }

        // Left Indicator 버튼
        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 110
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: -180
            width: 80
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
                onClicked: carModel.handleLeftIndicator()
            }
        }

        // Right Indicator 버튼
        Rectangle {
            anchors.top: parent.verticalCenter
            anchors.topMargin: 110
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: -180
            width: 80
            height: 60
            color: "#1DB954"
            radius: 20

            Text {
                anchors.centerIn: parent
                text: "RIGHT"
                font.pointSize: 18
                color: "#FFFFFF"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: carModel.handleRightIndicator()
            }
        }
    }
}
