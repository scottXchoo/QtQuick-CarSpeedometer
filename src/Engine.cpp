#include <QDebug>

#include "../include/Engine.h"
#include "../include/Car.h"

Engine::Engine(Car *car) : car_(car), target_speed_(100), current_acceleration_(0) {
  timer_ = new QTimer(this);

  connect(timer_, &QTimer::timeout, this, &Engine::updateSpeed);

  qDebug() << "Engine: Created";
}

Engine::~Engine() {
  if (timer_->isActive()) timer_->stop();
}

void Engine::accSlot() {
  if (!car_) return;
  qDebug() << "Engine: accSlot called";
  current_acceleration_ += 10;
  timer_->start(500); // 0.5 s마다 속도가 10씩 증가
}

void Engine::updateSpeed() {
  if (!car_) return;
  int new_speed = car_->get_current_speed() + current_acceleration_;
  if (new_speed >= target_speed_) {
	new_speed = target_speed_;
	timer_->stop();
  }
  qDebug() << "Engine: Updated speed is " << new_speed;
  car_->set_current_speed(new_speed);
}