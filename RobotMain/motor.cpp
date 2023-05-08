

#include "motor.h"

Motor::Motor(int motor1, int motor2, int speed1, int speed2) {
  motorPin1 = motor1;
  motorPin2 = motor2;
  speedPin1 = speed1;
  speedPin2 = speed2;
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
}

void Motor::forward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  analogWrite(speedPin1, 55);
  analogWrite(speedPin2, 55);
  Serial.println("Forward");
}

void Motor::backward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(speedPin1, 55);
  analogWrite(speedPin2, 55);
  Serial.println("Backward");
}

void Motor::left() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(speedPin1, 55);
  analogWrite(speedPin2, 55);
  Serial.println("Left");
}

void Motor::right() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  analogWrite(speedPin1, 55);
  analogWrite(speedPin2, 55);
  Serial.println("Right");
}

void Motor::stop() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  analogWrite(speedPin1, 0);
  analogWrite(speedPin2, 0);
  Serial.println("Stop");
}
