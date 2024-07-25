#include <QDebug>

#include "Car.h"
#include "Engine.h"
#include "constants.h"

Engine::Engine(Car *car)
	: car_(car),
	  max_speed_(MAX_SPEED),
	  min_speed_(MIN_SPEED),
	  current_acceleration_(0),
	  time_elapsed_(0),
	  is_decelerating_(false) {
  acc_timer_ = new QTimer(this);
  dec_timer_ = new QTimer(this);

  connect(acc_timer_, &QTimer::timeout, this, &Engine::updateSpeed);
  connect(dec_timer_, &QTimer::timeout, this, &Engine::decelerateGradually);

  // Engine과 Timer 객체 간의 상호작용이 많기에 동일한 스레드에서 실행 권장
  engine_thread_ = new QThread(this);
  this->moveToThread(engine_thread_);
  acc_timer_->moveToThread(engine_thread_);
  dec_timer_->moveToThread(engine_thread_);

  // QThread가 종료되면, QTimer & QThread 삭제
  connect(engine_thread_, &QThread::finished, acc_timer_, &QTimer::deleteLater);
  connect(engine_thread_, &QThread::finished, engine_thread_, &QTimer::deleteLater);
  connect(engine_thread_, &QThread::finished, dec_timer_, &Engine::deleteLater);

  engine_thread_->start();
}

Engine::~Engine() {
  if (acc_timer_->isActive()) acc_timer_->stop();
  if (dec_timer_->isActive()) dec_timer_->stop();
  engine_thread_->quit(); // QThread 종료 요청
  engine_thread_->wait(); // QThread가 종료될 때까지 대기
}

void Engine::accPressedSlot() {
  if (!car_) return;

  if (is_decelerating_) {
	is_decelerating_ = false;
	dec_timer_->stop();
  }

  current_acceleration_ = INIT_ACCELERATION;
  time_elapsed_ = 0;
  acc_timer_->start(TIMER_INTERVAL);
}

void Engine::accReleasedSlot() {
  if (!car_) return;

  acc_timer_->stop();
  time_elapsed_ = 0;

  is_decelerating_ = true;
  dec_timer_->start(TIMER_INTERVAL);
}

void Engine::decelerateGradually() {
  if (!car_ || !is_decelerating_) return;

  double updated_speed = car_->get_current_speed() - ACCELERATION;
  if (updated_speed <= 0) {
	updated_speed = 0;
	is_decelerating_ = false;
	dec_timer_->stop();
  }
  car_->set_current_speed(updated_speed);
}

void Engine::updateSpeed() {
  if (!car_) return;

  double sigmoid_acceleration = sigmoid(time_elapsed_);
  double updated_speed = car_->get_current_speed() + sigmoid_acceleration * ACCELERATION;

  if (updated_speed < min_speed_ || updated_speed > max_speed_) {
	if (updated_speed < min_speed_) updated_speed = min_speed_;
	if (updated_speed > max_speed_) updated_speed = max_speed_;
	acc_timer_->stop();
  }

  car_->set_current_speed(updated_speed);
  time_elapsed_ += TIMER_INTERVAL / 1000.0;
}