

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
  private:
    int trigPin, echoPin;
  public:
    Ultrasonic(int trig, int echo);
    int getDistance();
};

#endif
