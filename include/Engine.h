#ifndef ENGINE_H_
#define ENGINE_H_

#include <QObject>
#include <QTimer>
#include <QPointer>
#include <QThread>

class Car; // Forward declaration

class Engine : public QObject {
 Q_OBJECT

 public:
  explicit Engine(Car *car);
  ~Engine() override;

 public slots:
  void accPressedSlot();
  void accReleasedSlot();

 private slots:
  void updateSpeed();
  void decelerateGradually();

 private:
  QPointer<Car> car_;
  QTimer *acc_timer_;
  QTimer *dec_timer_;
  QThread *engine_thread_;
  int max_speed_;
  int min_speed_;
  double current_acceleration_;
  double time_elapsed_;
  bool is_decelerating_;
};

#endif //ENGINE_H_