#include <Arduino.h>
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trig, int echo) {
  trigPin = trig; // Assign the value of 'trig' to the member variable 'trigPin'
  echoPin = echo; // Assign the value of 'echo' to the member variable 'echoPin'
  pinMode(trigPin, OUTPUT); // Set the 'trigPin' as an output pin
  pinMode(echoPin, INPUT); // Set the 'echoPin' as an input pin
}

int Ultrasonic::getDistance() {
  digitalWrite(trigPin, LOW); // Set the 'trigPin' to LOW
  delayMicroseconds(2); // Delay for 2 microseconds
  digitalWrite(trigPin, HIGH); // Set the 'trigPin' to HIGH
  delayMicroseconds(10); // Delay for 10 microseconds
  digitalWrite(trigPin, LOW); // Set the 'trigPin' to LOW
  float Fdistance = pulseIn(echoPin, HIGH); // Measure the pulse duration on 'echoPin' when it's HIGH and store the result in 'Fdistance'
  Fdistance = Fdistance / 58; // Convert the pulse duration to distance in centimeters
  return static_cast<int>(Fdistance); // Convert 'Fdistance' to an integer and return it
}
