#ifndef INDICATOR_H_
#define INDICATOR_H_

#include <QObject>
#include <QPointer>
#include <QTimer>

class Car; // Forward declaration

class Indicator : public QObject {
 Q_OBJECT

 public:
  explicit Indicator(Car *car);
  ~Indicator() override = default;

 public slots:
  void leftIndicatorSlot();
  void rightIndicatorSlot();

 private:
  QPointer<Car> car_;
};

#endif //INDICATOR_H_
