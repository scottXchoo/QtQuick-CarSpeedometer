#ifndef CAR_H_
#define CAR_H_

#include <QObject>

class Engine;
class Indicator;

class Car : public QObject {
 Q_OBJECT
  Q_PROPERTY(int currentSpeed READ get_current_speed WRITE set_current_speed NOTIFY speedChangeSignal)
  Q_PROPERTY(bool isLeftIndicatorOn READ is_left_indicator_on NOTIFY leftIndicatorChangeSignal)

 public:
  explicit Car();
  ~Car() override;

  [[nodiscard]] int get_current_speed() const;
  void set_current_speed(int speed);

  [[nodiscard]] bool is_left_indicator_on() const;

 public slots:
  void handleAccSlot();
  void handleDecSlot();
  void handleLeftIndicatorSlot();

 signals:
  void accSignal();
  void decSignal();
  void speedChangeSignal(int speed);

  void leftIndicatorSignal();
  void leftIndicatorChangeSignal(bool isOn);

 private:
  int current_speed_ = 0;
  bool is_left_indicator_on_ = false;
  Engine *engine;
  Indicator *indicator;
};

#endif //CAR_H_
