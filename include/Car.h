#ifndef CAR_H_
#define CAR_H_

#include <QObject>

class Engine;

class Car : public QObject {
 Q_OBJECT
  Q_PROPERTY(int currentSpeed READ get_current_speed WRITE set_current_speed NOTIFY speedChangeSignal)

 public:
  explicit Car();
  ~Car() override;

  [[nodiscard]] int get_current_speed() const;
  void set_current_speed(int speed);

 public slots:
  void accSlot();

 signals:
  void accSignal();
  void speedChangeSignal(int speed);

 private:
  int current_speed_ = 0;
  Engine *engine;
};

#endif //CAR_H_
