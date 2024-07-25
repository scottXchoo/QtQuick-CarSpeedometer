#include <QDebug>

#include "Car.h"
#include "Engine.h"
#include "constants.h"

Engine::Engine(Car *car)
	: car_(car), max_speed_(MAX_SPEED), min_speed_(MIN_SPEED), current_acceleration_(INIT_ACCELERATION) {
  timer_ = new QTimer();

  connect(timer_, &QTimer::timeout, this, &Engine::updateSpeed);

  thread_ = new QThread(this);
  this->moveToThread(thread_);
  timer_->moveToThread(thread_);
  // Engine과 Timer 객체 간의 상호작용이 많기에 동일한 스레드에서 실행 권장

  connect(thread_, &QThread::finished, timer_, &QTimer::deleteLater);
  connect(thread_, &QThread::finished, thread_, &QTimer::deleteLater);
  // QThread가 종료되면, QTimer & QThread 삭제

  thread_->start();

  qDebug() << "Engine: Created";
}

Engine::~Engine() {
  if (timer_->isActive()) timer_->stop();
  thread_->quit(); // QThread 종료 요청
  thread_->wait(); // QThread가 종료될 때까지 대기
}

void Engine::accSlot() {
  if (!car_) return;

  qDebug() << "Engine: accSlot called";
  if (current_acceleration_ < 0) current_acceleration_ = 0;
  current_acceleration_ += ACCELERATION;
  timer_->start(TIMER_INTERVAL); // timeout 시그널을 INTERVAL마다 발생시킴
}

void Engine::decSlot() {
  if (!car_) return;

  qDebug() << "Engine: decSlot called";
  if (current_acceleration_ > 0) current_acceleration_ = 0;
  current_acceleration_ -= ACCELERATION;
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