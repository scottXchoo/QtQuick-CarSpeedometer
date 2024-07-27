#include "CarModel.h"
#include "Engine.h"
#include "Indicator.h"

CarModel::CarModel(QObject *parent)
	: QObject(parent), m_currentSpeed(0), m_leftIndicatorOn(false), m_rightIndicatorOn(false) {
  engine = new Engine(this);
  indicator = new Indicator(this);

  connect(engine, &Engine::speedChanged, this, &CarModel::setCurrentSpeed);
  connect(indicator, &Indicator::leftIndicatorChanged, this, &CarModel::setLeftIndicatorOn);
  connect(indicator, &Indicator::rightIndicatorChanged, this, &CarModel::setRightIndicatorOn);
}

CarModel::~CarModel() {
  delete engine;
  delete indicator;
}

double CarModel::currentSpeed() const {
  return m_currentSpeed;
}

bool CarModel::leftIndicatorOn() const {
  return m_leftIndicatorOn;
}

bool CarModel::rightIndicatorOn() const {
  return m_rightIndicatorOn;
}

void CarModel::setCurrentSpeed(double speed) {
  if (m_currentSpeed != speed) {
	m_currentSpeed = speed;
	emit currentSpeedChanged(speed);
  }
}

void CarModel::setLeftIndicatorOn(bool on) {
  if (m_leftIndicatorOn != on) {
	m_leftIndicatorOn = on;
	emit leftIndicatorOnChanged(on);
  }
}

void CarModel::setRightIndicatorOn(bool on) {
  if (m_rightIndicatorOn != on) {
	m_rightIndicatorOn = on;
	emit rightIndicatorOnChanged(on);
  }
}

void CarModel::handleAccPressed() {
  engine->accPressed();
}

void CarModel::handleAccReleased() {
  engine->accReleased();
}

void CarModel::handleBrakePressed() {
  engine->brakePressed();
}

void CarModel::handleBrakeReleased() {
  engine->brakeReleased();
}

void CarModel::handleLeftIndicator() {
  indicator->toggleLeftIndicator();
}

void CarModel::handleRightIndicator() {
  indicator->toggleRightIndicator();
}
