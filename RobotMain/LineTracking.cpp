#include <Arduino.h>
#include "LineTracking.h"

LineTracking::LineTracking() {
  LT_R = A0; // Assign pin A0 to LT_R
  LT_M = A1; // Assign pin A1 to LT_M
  LT_L = A2; // Assign pin A2 to LT_L
}

void LineTracking::setup() {
  pinMode(LT_R, INPUT); // Set pin LT_R as input
  pinMode(LT_M, INPUT); // Set pin LT_M as input
  pinMode(LT_L, INPUT); // Set pin LT_L as input
  pinMode(3, OUTPUT); // Set pin 3 as output for Standby
  digitalWrite(3, HIGH); // Set pin 3 to high (ON)
  Serial.begin(9600); // Initialize the serial communication at 9600 baud rate
}

void LineTracking::move() {
  if (analogRead(LT_M) > 200 && analogRead(LT_M) < 850) { // If the value read from LT_M is between 200 and 850, go forward
    forward();
  }
  else if (analogRead(LT_R) > 400 ) { // If the value read from LT_R is over 400, turn right
    right();
  }
  else if (analogRead(LT_L) > 50) { // If the value read from LT_L is over 50, turn left
    left();
  }
  else if (analogRead(LT_M) < 851 && analogRead(LT_L) < 851 && analogRead(LT_R) < 851) { // If the values read from all sensors are below 851, turn right (Turn around if no back line is detected)
    right();
  }
}

void LineTracking::forward() {
  digitalWrite(7, HIGH); // Turn on the left motors
  digitalWrite(8, HIGH); // Turn on the right motors
  analogWrite(5, 55); // Set the speed for the left motors
  analogWrite(6, 55); // Set the speed for the right motors
  Serial.println("forward!"); // Print "forward!" when the forward function is in use
}

void LineTracking::back() {
  digitalWrite(7, LOW); // Turn off the left motors
  digitalWrite(8, LOW); // Turn off the right motors
  analogWrite(5, 55); // Set the speed for the left motors
  analogWrite(6, 55); // Set the speed for the right motors
  Serial.println("back!"); // Print "back!" when the back function is in use
}

void LineTracking::left() {
  digitalWrite(7, HIGH); // Turn on the left motors
  digitalWrite(8, LOW); // Turn off the right motors
  analogWrite(5, 55); // Set the speed for the left motors
  analogWrite(6, 55); // Set the speed for the right motors
  Serial.println("left!"); // Print "left!" when the left function is in use
}

void LineTracking::right() {
  digitalWrite(7, LOW); // Turn off the left motors
  digitalWrite(8, HIGH); // Turn on the right motors
  analogWrite(5, 55); // Set the speed for the left motors
  analogWrite(6, 55); // Set the speed for the right motors
  Serial.println("right!"); // Print "right!" when the right function is in use
}

void LineTracking::stop() {
  digitalWrite(7, LOW); // Turn off the left motors
  digitalWrite(8, LOW); // Turn off the right motors
  analogWrite(5, 0); // Set the speed for the left motors to 0
  analogWrite(6, 0); // Set the speed for the right motors to 0
  Serial.println("stop!"); // Print "stop!" when the stop function is called
}
