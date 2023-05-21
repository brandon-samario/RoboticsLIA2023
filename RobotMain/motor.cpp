#include "motor.h"

Motor::Motor(int motor1, int motor2, int speed1, int speed2) {
  motorPin1 = motor1;  // Assigning the value of motor1 to the member variable motorPin1
  motorPin2 = motor2;  // Assigning the value of motor2 to the member variable motorPin2
  speedPin1 = speed1;  // Assigning the value of speed1 to the member variable speedPin1
  speedPin2 = speed2;  // Assigning the value of speed2 to the member variable speedPin2
  pinMode(motorPin1, OUTPUT);  // Setting motorPin1 as an output pin
  pinMode(motorPin2, OUTPUT);  // Setting motorPin2 as an output pin
  pinMode(speedPin1, OUTPUT);  // Setting speedPin1 as an output pin
  pinMode(speedPin2, OUTPUT);  // Setting speedPin2 as an output pin
}

void Motor::forward() {
  digitalWrite(motorPin1, HIGH);  // Set motorPin1 to HIGH (turn on motor)
  digitalWrite(motorPin2, HIGH);  // Set motorPin2 to HIGH (turn on motor)
  analogWrite(speedPin1, 55);  // Set the speed of motorPin1 to 55 (using PWM)
  analogWrite(speedPin2, 55);  // Set the speed of motorPin2 to 55 (using PWM)
  Serial.println("Forward");  // Print "Forward" to the serial monitor
}

void Motor::backward() {
  digitalWrite(motorPin1, LOW);  // Set motorPin1 to LOW (turn off motor)
  digitalWrite(motorPin2, LOW);  // Set motorPin2 to LOW (turn off motor)
  analogWrite(speedPin1, 55);  // Set the speed of motorPin1 to 55 (using PWM)
  analogWrite(speedPin2, 55);  // Set the speed of motorPin2 to 55 (using PWM)
  Serial.println("Backward");  // Print "Backward" to the serial monitor
}

void Motor::left() {
  digitalWrite(motorPin1, HIGH);  // Set motorPin1 to HIGH (turn on motor)
  digitalWrite(motorPin2, LOW);  // Set motorPin2 to LOW (turn off motor)
  analogWrite(speedPin1, 55);  // Set the speed of motorPin1 to 55 (using PWM)
  analogWrite(speedPin2, 55);  // Set the speed of motorPin2 to 55 (using PWM)
  Serial.println("Left");  // Print "Left" to the serial monitor
}

void Motor::right() {
  digitalWrite(motorPin1, LOW);  // Set motorPin1 to LOW (turn off motor)
  digitalWrite(motorPin2, HIGH);  // Set motorPin2 to HIGH (turn on motor)
  analogWrite(speedPin1, 55);  // Set the speed of motorPin1 to 55 (using PWM)
  analogWrite(speedPin2, 55);  // Set the speed of motorPin2 to 55 (using PWM)
  Serial.println("Right");  // Print "Right" to the serial monitor
}

void Motor::stop() {
  digitalWrite(motorPin1, HIGH);  // Set motorPin1 to HIGH (turn on motor)
  digitalWrite(motorPin2, HIGH);  // Set motorPin2 to HIGH (turn on motor)
  analogWrite(speedPin1, 0);  // Set the speed of motorPin1 to 0 (stop the motor)
  analogWrite(speedPin2, 0);  // Set the speed of motorPin2 to 0 (stop the motor)
  Serial.println("Stop");  // Print "Stop" to the serial monitor
}
