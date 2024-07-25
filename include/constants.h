#ifndef CONSTANTS_H_
#define CONSTANTS_H_

constexpr int MAX_SPEED = 200;
constexpr int MIN_SPEED = 0;
constexpr int INIT_ACCELERATION = 0;
constexpr double ACCELERATION = 4.3;
constexpr int TIMER_INTERVAL = 100;
constexpr int BRAKE_ACCELERATION = 5;

constexpr double SIGMA = 1;
constexpr double BRAKE_SIGMA = 3;

double sigmoid(double x, double k) {
  return k / (1.0 + exp(-x));
}
#endif //CONSTANTS_H_