#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h> // Include the Arduino library for access to its functions and types

class Motor {
  private:
    int motorPin1, motorPin2, speedPin1, speedPin2; // Private member variables to store pin numbers for the motor control
  public:
    Motor(int motor1, int motor2, int speed1, int speed2); // Constructor for the Motor class that takes pin numbers as parameters
    void forward(); // Method to make the motor move forward
    void backward(); // Method to make the motor move backward
    void left(); // Method to make the motor turn left
    void right(); // Method to make the motor turn right
    void stop(); // Method to stop the motor
};

#endif // MOTOR_H
