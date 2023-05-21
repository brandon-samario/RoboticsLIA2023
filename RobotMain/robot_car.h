#ifndef ROBOT_CAR_H
#define ROBOT_CAR_H

#include <Arduino.h> // Include the Arduino library for using Arduino functions and types.

class RobotCar{
  private:
    int _pinA1; // Private variable to store the pin number for motor A1.
    int _pinA2; // Private variable to store the pin number for motor A2.
    int _pinB1; // Private variable to store the pin number for motor B1.
    int _pinB2; // Private variable to store the pin number for motor B2.
    int _standby; // Private variable to store the pin number for standby mode.
  public:
    RobotCar(int _pinA1,int _pinA2,int _pinB1, int _pinB2, int _standby); // Constructor for the RobotCar class, which initializes the pin numbers.
    void init(); // Public method to initialize the robot car.
    void forward(); // Public method to move the robot car forward.
    void backward(); // Public method to move the robot car backward.
    void left(); // Public method to turn the robot car left.
    void right(); // Public method to turn the robot car right.
    void stop(); // Public method to stop the robot car.   
};

#endif
