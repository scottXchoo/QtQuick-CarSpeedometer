#include "Engine.h"
#include "CarModel.h"
#include "constants.h"

Engine::Engine(CarModel *carModel)
	: carModel_(carModel), current_acceleration_(0), time_elapsed_(0),
	  is_decelerating_(false), is_breaking_(false) {

  acc_timer_ = new QTimer(this);
  dec_timer_ = new QTimer(this);
  brake_timer_ = new QTimer(this);

  connect(acc_timer_, &QTimer::timeout, this, &Engine::updateAccSpeed);
  connect(dec_timer_, &QTimer::timeout, this, &Engine::updateDecSpeed);
  connect(brake_timer_, &QTimer::timeout, this, &Engine::updateBrakeSpeed);
}

Engine::~Engine() {
  if (acc_timer_->isActive()) acc_timer_->stop();
  if (dec_timer_->isActive()) dec_timer_->stop();
  if (brake_timer_->isActive()) brake_timer_->stop();
}

void Engine::accPressed() {
  if (is_decelerating_) {
	is_decelerating_ = false;
	dec_timer_->stop();
  }

  if (is_breaking_) {
	is_breaking_ = false;
	brake_timer_->stop();
  }

  current_acceleration_ = INIT_ACCELERATION;
  time_elapsed_ = 0;
  acc_timer_->start(TIMER_INTERVAL);
}

void Engine::accReleased() {
  acc_timer_->stop();
  time_elapsed_ = 0;

  is_decelerating_ = true;
  dec_timer_->start(TIMER_INTERVAL);
}

void Engine::brakePressed() {
  if (acc_timer_->isActive()) {
	acc_timer_->stop();
	time_elapsed_ = 0;
  }

  if (is_decelerating_) {
	dec_timer_->stop();
	is_decelerating_ = false;
  }

  is_breaking_ = true;
  time_elapsed_ = 0;
  brake_timer_->start(TIMER_INTERVAL);
}

void Engine::brakeReleased() {
  if (is_breaking_) {
	is_breaking_ = false;
	brake_timer_->stop();
  }

  is_decelerating_ = true;
  dec_timer_->start(TIMER_INTERVAL);
}

void Engine::updateAccSpeed() {
  double sigmoid_acceleration = sigmoid(time_elapsed_, SIGMA);
  double updated_speed = carModel_->currentSpeed() + sigmoid_acceleration * ACCELERATION;

  if (updated_speed < MIN_SPEED || updated_speed > MAX_SPEED) {
	if (updated_speed < MIN_SPEED) updated_speed = MIN_SPEED;
	if (updated_speed > MAX_SPEED) updated_speed = MAX_SPEED;
	acc_timer_->stop();
  }

  emit speedChanged(updated_speed);
  time_elapsed_ += TIMER_INTERVAL / 1000.0;
}

void Engine::updateDecSpeed() {
  if (!is_decelerating_) return;

  double updated_speed = carModel_->currentSpeed() - ACCELERATION;
  if (updated_speed <= 0) {
	updated_speed = 0;
	is_decelerating_ = false;
	dec_timer_->stop();
  }

  emit speedChanged(updated_speed);
}

void Engine::updateBrakeSpeed() {
  if (!is_breaking_) return;

  double sigmoid_deceleration = sigmoid(time_elapsed_, BRAKE_SIGMA);
  double updated_speed = carModel_->currentSpeed() - sigmoid_deceleration * BRAKE_ACCELERATION;

  if (updated_speed <= 0) {
	updated_speed = 0;
	is_breaking_ = false;
	brake_timer_->stop();
  }

  emit speedChanged(updated_speed);
  time_elapsed_ += TIMER_INTERVAL / 1000.0;
}
