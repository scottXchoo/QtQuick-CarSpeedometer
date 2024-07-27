#ifndef CARMODEL_H
#define CARMODEL_H

#include <QObject>

class Engine;
class Indicator;

class CarModel : public QObject {
 Q_OBJECT
  Q_PROPERTY(double currentSpeed READ currentSpeed NOTIFY currentSpeedChanged)
  Q_PROPERTY(bool leftIndicatorOn READ leftIndicatorOn NOTIFY leftIndicatorOnChanged)
  Q_PROPERTY(bool rightIndicatorOn READ rightIndicatorOn NOTIFY rightIndicatorOnChanged)

 public:
  explicit CarModel(QObject *parent = nullptr);
  ~CarModel();

  double currentSpeed() const;
  bool leftIndicatorOn() const;
  bool rightIndicatorOn() const;

 public slots:
  void handleAccPressed();
  void handleAccReleased();
  void handleBrakePressed();
  void handleBrakeReleased();
  void handleLeftIndicator();
  void handleRightIndicator();

 signals:
  void currentSpeedChanged(double speed);
  void leftIndicatorOnChanged(bool on);
  void rightIndicatorOnChanged(bool on);

 private:
  double m_currentSpeed;
  bool m_leftIndicatorOn;
  bool m_rightIndicatorOn;

  Engine *engine;
  Indicator *indicator;

  void setCurrentSpeed(double speed);
  void setLeftIndicatorOn(bool on);
  void setRightIndicatorOn(bool on);
};

#endif // CARMODEL_H
