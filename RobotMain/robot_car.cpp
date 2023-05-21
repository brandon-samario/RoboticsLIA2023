#include "robot_car.h"

RobotCar::RobotCar(int pinA1, int pinA2, int pinB1, int pinB2, int standby) {
  _pinA1 = pinA1; // Assigning the value of pinA1 to the private member variable _pinA1
  _pinA2 = pinA2; // Assigning the value of pinA2 to the private member variable _pinA2
  _pinB1 = pinB1; // Assigning the value of pinB1 to the private member variable _pinB1
  _pinB2 = pinB2; // Assigning the value of pinB2 to the private member variable _pinB2
  _standby = standby; // Assigning the value of standby to the private member variable _standby
}

void RobotCar::init() {
  pinMode(_pinA1, OUTPUT); // Configuring _pinA1 as an output pin
  pinMode(_pinA2, OUTPUT); // Configuring _pinA2 as an output pin
  pinMode(_pinB1, OUTPUT); // Configuring _pinB1 as an output pin
  pinMode(_pinB2, OUTPUT); // Configuring _pinB2 as an output pin
  pinMode(_standby, OUTPUT); // Configuring _standby as an output pin
  digitalWrite(_standby, HIGH); // Setting the value of _standby pin to HIGH (logical high)
}

void RobotCar::forward() {
  digitalWrite(_pinA1, HIGH); // Setting _pinA1 to HIGH (logical high)
  digitalWrite(_pinA2, HIGH); // Setting _pinA2 to HIGH (logical high)
  analogWrite(_pinB1, 55); // Setting the PWM value of _pinB1 to 55 (analog output)
  analogWrite(_pinB2, 55); // Setting the PWM value of _pinB2 to 55 (analog output)
}

void RobotCar::backward() {
  digitalWrite(_pinA1, LOW); // Setting _pinA1 to LOW (logical low)
  digitalWrite(_pinA2, LOW); // Setting _pinA2 to LOW (logical low)
  analogWrite(_pinB1, 55); // Setting the PWM value of _pinB1 to 55 (analog output)
  analogWrite(_pinB2, 55); // Setting the PWM value of _pinB2 to 55 (analog output)
}

void RobotCar::left() {
  digitalWrite(_pinA1, HIGH); // Setting _pinA1 to HIGH (logical high)
  digitalWrite(_pinA2, LOW); // Setting _pinA2 to LOW (logical low)
  analogWrite(_pinB1, 55); // Setting the PWM value of _pinB1 to 55 (analog output)
  analogWrite(_pinB2, 55); // Setting the PWM value of _pinB2 to 55 (analog output)
}

void RobotCar::right() {
  digitalWrite(_pinA1, LOW); // Setting _pinA1 to LOW (logical low)
  digitalWrite(_pinA2, HIGH); // Setting _pinA2 to HIGH (logical high)
  analogWrite(_pinB1, 55); // Setting the PWM value of _pinB1 to 55 (analog output)
  analogWrite(_pinB2, 55); // Setting the PWM value of _pinB2 to 55 (analog output)
}

void RobotCar::stop() {
  digitalWrite(_pinA1, LOW); // Setting _pinA1 to LOW (logical low)
  digitalWrite(_pinA2, LOW); // Setting _pinA2 to LOW (logical low)
  analogWrite(_pinB1, 0); // Setting the PWM value of _pinB1 to 0 (analog output)
  analogWrite(_pinB2, 0); // Setting the PWM value of _pinB2 to 0 (analog output)
}
