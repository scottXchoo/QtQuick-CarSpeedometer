#ifndef CONSTANTS_H_
#define CONSTANTS_H_

constexpr int MAX_SPEED = 200;
constexpr int MIN_SPEED = 0;
constexpr int INIT_ACCELERATION = 0;
constexpr double ACCELERATION = 3.7;
constexpr int TIMER_INTERVAL = 50;

const double INPUT_LAYER_SIZE = 1.3;
double sigmoid(double x) {
  return INPUT_LAYER_SIZE / (1.0 + exp(-x));
}
#endif //CONSTANTS_H_