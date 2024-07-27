#include "Indicator.h"
#include "CarModel.h"

Indicator::Indicator(CarModel *carModel) : carModel_(carModel) {}

void Indicator::toggleLeftIndicator() {
  bool newState = !carModel_->leftIndicatorOn();
  emit leftIndicatorChanged(newState);

  if (carModel_->rightIndicatorOn()) {
	emit rightIndicatorChanged(false);
  }
}

void Indicator::toggleRightIndicator() {
  bool newState = !carModel_->rightIndicatorOn();
  emit rightIndicatorChanged(newState);

  if (carModel_->leftIndicatorOn()) {
	emit leftIndicatorChanged(false);
  }
}
