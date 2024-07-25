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
  void accSlot();
  void decSlot();

 private slots:
  void updateSpeed();

 private:
  QPointer<Car> car_;
  QTimer *timer_;
  QThread *thread_;
  int max_speed_;
  int min_speed_;
  double current_acceleration_;
};

#endif //ENGINE_H_