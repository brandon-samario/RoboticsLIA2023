

#include <Arduino.h>
#include "LineTracking.h"

LineTracking::LineTracking() {
  LT_R = A0;
  LT_M = A1;
  LT_L = A2;
}

void LineTracking::setup() {
  pinMode(LT_R, INPUT);
  pinMode(LT_M, INPUT);
  pinMode(LT_L, INPUT);
  pinMode(3, OUTPUT); //Standby
  digitalWrite(3, HIGH);
  Serial.begin(9600);
}

void LineTracking::move() {
  if (analogRead(LT_M) > 200 && analogRead(LT_M) < 850) { //Value between 200 and 850 will go forward
    forward();
  }
  else if (analogRead(LT_R) > 400 ) { //Value over 400 will turn right
    right();
  }
  else if (analogRead(LT_L) > 50) { //Value over 50 will turn left
    left();
  }
  else if (analogRead(LT_M) < 851 && analogRead(LT_L) < 851 && analogRead(LT_R) < 851) { //If value of all sensors is above 850 it will turn right (Turn around if not back line is detected)
    right();
  }
}

void LineTracking::forward() {
  digitalWrite(7, HIGH); //Left motors ON
  digitalWrite(8, HIGH); //Right motors ON
  analogWrite(5, 55); //Set Speed for left motors
  analogWrite(6, 55); //Set Speed for right motors
  Serial.println("forward!"); //Text printed when forward function is in use
}

void LineTracking::back() {
  digitalWrite(7, LOW); //Left motors OFF
  digitalWrite(8, LOW); //Right motors OFF
  analogWrite(5, 55); //Set Speed for left motors
  analogWrite(6, 55); //Set Speed for right motors
  Serial.println("back!"); //Text printed when back function is in use
}

void LineTracking::left() {
  digitalWrite(7, HIGH); //Left motors ON
  digitalWrite(8, LOW); //Right motors OFF
  analogWrite(5, 55); //Set Speed for left motors
  analogWrite(6, 55); //Set Speed for right motors
  Serial.println("left!"); //Text printed when left function is in use
}

void LineTracking::right() {
  digitalWrite(7, LOW); //Left motors OFF
  digitalWrite(8, HIGH); //Right motors ON
  analogWrite(5, 55); //Set Speed for left motors
  analogWrite(6, 55); //Set Speed for right motors
  Serial.println("right!"); //Text printed when right function is in use
}

void LineTracking::stop() {
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  analogWrite(5, 0); //Set Speed for left
  analogWrite(6, 0);
  Serial.println("stop!");
}
