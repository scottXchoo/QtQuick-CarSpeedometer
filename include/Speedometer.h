#ifndef SPEEDOMETER_H_
#define SPEEDOMETER_H_

#include <QObject>
#include <QDebug>

class Speedometer : public QObject {
 Q_OBJECT

 public:
  explicit Speedometer(QObject *parent = nullptr);
  ~Speedometer() override = default;

 public slots:
  static void updateSpeedSlot(int speed);
};

#endif //SPEEDOMETER_H_
