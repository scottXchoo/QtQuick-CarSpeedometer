#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "../include/Speedometer.h"
#include "../include/Car.h"

Speedometer::Speedometer(QObject *parent) : QObject(parent) {
  qDebug() << "Speedometer: Created";
}

void Speedometer::updateSpeedSlot(int speed) {
  qDebug() << "Speedometer: " << speed;
}