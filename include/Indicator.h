#ifndef INDICATOR_H
#define INDICATOR_H

#include <QObject>

class CarModel;

class Indicator : public QObject {
 Q_OBJECT

 public:
  explicit Indicator(CarModel *carModel);

 signals:
  void leftIndicatorChanged(bool on);
  void rightIndicatorChanged(bool on);

 public slots:
  void toggleLeftIndicator();
  void toggleRightIndicator();

 private:
  CarModel *carModel_;
};

#endif // INDICATOR_H
