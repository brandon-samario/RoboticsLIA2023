#ifndef ULTRASONIC_H  // Header guard to prevent multiple inclusions of the header file
#define ULTRASONIC_H

class Ultrasonic {
  private:
    int trigPin, echoPin;  // Private member variables to store the trigger and echo pins
  public:
    Ultrasonic(int trig, int echo);  // Constructor to initialize the Ultrasonic object with trigger and echo pin numbers
    int getDistance();  // Member function to retrieve the distance measured by the ultrasonic sensor
};

#endif  // End of header guard
