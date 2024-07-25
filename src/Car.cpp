#include "Car.h"
#include "Engine.h"
#include "Indicator.h"

#include <QDebug>

Car::Car() : current_speed_(0) {
  engine = new Engine(this);
  indicator = new Indicator(this);

  // QueuedConnection: signal과 slot이 서로 다른 스레드에서 실행될 때, 유용함 (vs DirectConnection)
  // 하지만, 기본값으로 다른 스레드에 있으면 알아서 QueuedConnection으로 동작함
  connect(this, &Car::accPressedSignal, engine, &Engine::accPressedSlot);
  connect(this, &Car::accReleasedSignal, engine, &Engine::accReleasedSlot);

  // connect(this, &Car::decSignal, engine, &Engine::decSlot);
  connect(this, &Car::leftIndicatorSignal, indicator, &Indicator::leftIndicatorSlot);
  connect(this, &Car::rightIndicatorSignal, indicator, &Indicator::rightIndicatorSlot);
}

Car::~Car() {
  delete engine;
  delete indicator;
}

double Car::get_current_speed() const {
  return current_speed_;
}

void Car::set_current_speed(double speed) {
  if (current_speed_ == speed) return;
  current_speed_ = speed;
  emit speedChangeSignal(current_speed_);
}

void Car::handleAccPressedSlot() {
  emit accPressedSignal();
}

void Car::handleAccReleasedSlot() {
  emit accReleasedSignal();
}

bool Car::is_left_indicator_on() const {
  return is_left_indicator_on_;
}

void Car::handleLeftIndicatorSlot() {
  is_left_indicator_on_ = !is_left_indicator_on_;
  emit leftIndicatorSignal();
  emit leftIndicatorChangeSignal(is_left_indicator_on_);
}

bool Car::is_right_indicator_on() const {
  return is_right_indicator_on_;
}

void Car::handleRightIndicatorSlot() {
  is_right_indicator_on_ = !is_right_indicator_on_;
  emit rightIndicatorSignal();
  emit rightIndicatorChangeSignal(is_right_indicator_on_);
}