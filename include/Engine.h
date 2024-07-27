#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QTimer>

class CarModel;

class Engine : public QObject {
 Q_OBJECT

 public:
  Engine(CarModel *carModel);
  ~Engine();

 signals:
  void speedChanged(double speed);

 public slots:
  void accPressed();
  void accReleased();
  void brakePressed();
  void brakeReleased();

 private slots:
  void updateAccSpeed();
  void updateDecSpeed();
  void updateBrakeSpeed();

 private:
  CarModel *carModel_;
  QTimer *acc_timer_;
  QTimer *dec_timer_;
  QTimer *brake_timer_;
  double current_acceleration_;
  double time_elapsed_;
  bool is_decelerating_;
  bool is_breaking_;
};

#endif // ENGINE_H
