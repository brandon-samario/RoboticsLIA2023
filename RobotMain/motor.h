

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  private:
    int motorPin1, motorPin2, speedPin1, speedPin2;
  public:
    Motor(int motor1, int motor2, int speed1, int speed2);
    void forward();
    void backward();
    void left();
    void right();
    void stop();
};

#endif // MOTOR_H
