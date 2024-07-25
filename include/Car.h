#ifndef CAR_H_
#define CAR_H_

#include <QObject>

class Engine;
class Indicator;

class Car : public QObject {
 Q_OBJECT
  Q_PROPERTY(double currentSpeed READ get_current_speed WRITE set_current_speed NOTIFY speedChangeSignal)
  Q_PROPERTY(bool isLeftIndicatorOn READ is_left_indicator_on NOTIFY leftIndicatorChangeSignal)
  Q_PROPERTY(bool isRightIndicatorOn READ is_right_indicator_on NOTIFY rightIndicatorChangeSignal)

 public:
  explicit Car();
  ~Car() override;

  [[nodiscard]] double get_current_speed() const;
  void set_current_speed(double speed);

  [[nodiscard]] bool is_left_indicator_on() const;
  [[nodiscard]] bool is_right_indicator_on() const;

 public slots:
  void handleAccPressedSlot();
  void handleAccReleasedSlot();
  void handleBrakePressedSlot();
  void handleBrakeReleasedSlot();

  void handleLeftIndicatorSlot();
  void handleRightIndicatorSlot();

 signals:
  void accPressedSignal();
  void accReleasedSignal();
  void brakePressedSignal();
  void brakeReleasedSignal();
  void speedChangeSignal(double speed);

  void leftIndicatorSignal();
  void leftIndicatorChangeSignal(bool isOn);
  void rightIndicatorSignal();
  void rightIndicatorChangeSignal(bool isOn);

 private:
  double current_speed_ = 0;
  bool is_left_indicator_on_ = false;
  bool is_right_indicator_on_ = false;

  Engine *engine;
  Indicator *indicator;
};

#endif //CAR_H_
