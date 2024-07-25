#include "Car.h"
#include "Engine.h"

#include <QDebug>

Car::Car() : current_speed_(0) {
  engine = new Engine(this);

  connect(this, &Car::accSignal, engine, &Engine::accSlot);
  connect(this, &Car::decSignal, engine, &Engine::decSlot);

  qDebug() << "Car: Created";
}

Car::~Car() {
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

void Car::decSlot() {
  qDebug() << "Car: decSlot called";
  emit decSignal();
}