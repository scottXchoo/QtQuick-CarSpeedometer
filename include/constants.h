#ifndef CONSTANTS_H_
#define CONSTANTS_H_

constexpr int MAX_SPEED = 200;
constexpr int MIN_SPEED = 0;
constexpr int INIT_ACCELERATION = 0;
constexpr int ACCELERATION = 2;

constexpr int TIMER_INTERVAL = 50;

double sigmoid(double x) {
  return x >= 0 ? 1.0 / (1.0 + exp(-x)) : -1.0 / (1.0 + exp(x));
}

#endif //CONSTANTS_H_