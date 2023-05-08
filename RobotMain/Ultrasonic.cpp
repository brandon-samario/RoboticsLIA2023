

#include <Arduino.h>
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trig, int echo) {
  trigPin = trig;
  echoPin = echo;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int Ultrasonic::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float Fdistance = pulseIn(echoPin, HIGH);
  Fdistance = Fdistance / 58;
  return static_cast<int>(Fdistance);
}
