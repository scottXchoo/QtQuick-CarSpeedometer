#include <QDebug>

#include "Car.h"
#include "Engine.h"
#include "constants.h"

Engine::Engine(Car *car)
	: car_(car), max_speed_(MAX_SPEED), min_speed_(MIN_SPEED), current_acceleration_(INIT_ACCELERATION) {
  timer_ = new QTimer(this);

  connect(timer_, &QTimer::timeout, this, &Engine::updateSpeed);

  qDebug() << "Engine: Created";
}

Engine::~Engine() {
  if (timer_->isActive()) timer_->stop();
  delete timer_;
}

void Engine::accSlot() {
  if (!car_) return;
  qDebug() << "Engine: accSlot called";
  current_acceleration_ = ACCELERATION;
  timer_->start(TIMER_INTERVAL); // timeout 시그널을 INTERVAL마다 발생시킴
}

void Engine::decSlot() {
  if (!car_) return;
  qDebug() << "Engine: decSlot called";
  current_acceleration_ = ACCELERATION * -1;
  timer_->start(TIMER_INTERVAL);
}

void Engine::updateSpeed() {
  if (!car_) return;

  double sigmoid_acceleration = sigmoid(current_acceleration_);
  double new_speed = car_->get_current_speed() + sigmoid_acceleration * ACCELERATION;
  qDebug() << "Engine: Updated speed is " << car_->get_current_speed();

  if (new_speed < min_speed_ || new_speed > max_speed_) {
	if (new_speed < min_speed_) new_speed = min_speed_;
	if (new_speed > max_speed_) new_speed = max_speed_;
	timer_->stop();
  }

  car_->set_current_speed(new_speed);
}