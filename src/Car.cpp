#include <QDebug>

#include "../include/Car.h"
#include "../include/Speedometer.h"
#include "../include/Engine.h"

Car::Car() : current_speed_(0) {
  speedometer = new Speedometer(this);
  engine = new Engine(this);

  connect(this, &Car::accSignal, engine, &Engine::accSlot);
  connect(this, &Car::speedChangeSignal, speedometer, &Speedometer::updateSpeedSlot);

  qDebug() << "Car: Created";
}

Car::~Car() {
  delete speedometer;
  delete engine;
}

int Car::get_current_speed() const {
  qDebug() << "Car: Getting current speed: " << current_speed_;
  return current_speed_;
}

void Car::set_current_speed(int speed) {
  if (current_speed_ == speed) return;
  qDebug() << "Car: Setting current speed to " << speed;
  current_speed_ = speed;
  emit speedChangeSignal(current_speed_);
}

void Car::accSlot() {
  qDebug() << "Car: accSlot called";
  emit accSignal();
}