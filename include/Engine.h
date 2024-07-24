#ifndef ENGINE_H_
#define ENGINE_H_

#include <QObject>
#include <QTimer>
#include <QPointer>

class Car; // Forward declaration

class Engine : public QObject {
 Q_OBJECT

 public:
  explicit Engine(Car *car);
  ~Engine() override;

 public slots:
  void accSlot();

 private:
  QPointer<Car> car_;
  QTimer *timer_;
  int target_speed_;
  int current_acceleration_;

  void updateSpeed();
};

#endif //ENGINE_H_
