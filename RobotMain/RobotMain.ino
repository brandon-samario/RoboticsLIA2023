#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>

#include "Ultrasonic.h"
#include "motor.h"
#include "LineTracking.h"
#include "robot_car.h"

#define F 16736925  //FORWARD (PRESS)
#define B 16754775  //BACK (PRESS)
#define L 16720605  //LEFT (PRESS)
#define R 16761405  //RIGHT (PRESS)
#define S 16712445  //STOP (PRESS)

#define UNKNOWN_F 5316027     //FORWARD (HOLD)
#define UNKNOWN_B 2747854299  //BACK (HOLD)
#define UNKNOWN_L 1386468383  //LEFT (HOLD)
#define UNKNOWN_R 553536955   //RIGHT (HOLD)
#define UNKNOWN_S 3622325019  //STOP (HOLD)

const int echoPin = 12; // Hook up HC-SR04 echo to Arduino pin 12
const int trigPin = 13; // Hook up HC-SR04 trigger to Arduino pin 13
const int motorPin1 = 7; // pin 7 connected to motor 1
const int motorPin2 = 8; // pin 8 connected to motor 2
const int speedPin1 = 5; // pin 5 connected to motor 1
const int speedPin2 = 6; // pin 6 connected to motor 2

unsigned long preMillis;

int rightDist = 0, middleDist = 0, leftDist = 0;

Servo myservo;
Ultrasonic ultrasonic(trigPin, echoPin);
Motor motor1(motorPin1, motorPin2, speedPin1, speedPin2);
Motor motor2(motorPin2, motorPin1, speedPin2, speedPin1);

LineTracking robot;
IRrecv irrecv (9);
decode_results results;
RobotCar car(7, 8, 5, 6, 3); // Initialize the RobotCar object

void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  Serial.begin(9600);

  // Servo setup
  myservo.attach(10);
  myservo.write(70);

  // Motor setup
  motor1.stop();
  motor2.stop();

  // Line tracking setup
  robot.setup();

  // IR receiver setup
  car.init();
  irrecv.enableIRIn();
}

void loop() {
  // Ultrasonic sensor and motor control
  myservo.write(70);
  delay(500);
  middleDist = ultrasonic.getDistance();

  if (middleDist <= 30) {
    motor1.stop();
    motor2.stop();
    delay(500);

    // Move servo to the right to check distance
    myservo.write(-20);
    delay(1000);
    rightDist = ultrasonic.getDistance();

    // Move servo to the middle
    myservo.write(70);
    delay(500);

    // Move servo to the left to check distance
    myservo.write(160);
    delay(1000);
    leftDist = ultrasonic.getDistance();

    // Move servo back to the middle
    myservo.write(70);
    delay(500);

    if (rightDist > leftDist) {
      motor2.right();
      delay(300);
    } else if (leftDist > rightDist) {
      motor1.left();
      delay(300);
    } else if ((rightDist <= 30) || (leftDist <= 30)) {
      motor1.backward();
      motor2.backward();
      delay(300);
    } else {
      motor1.forward();
      motor2.forward();
    }
  } else {
    motor1.forward();
    motor2.forward();
  }

  // Line tracking
  robot.move();

  // IR remote control
  if (irrecv.decode(&results)) {
    preMillis = millis();
    irrecv.resume(); // Receive the next value
    switch (results.value) {
      case F:
      case UNKNOWN_F: car.forward(); break;
      case B:
      case UNKNOWN_B: car.backward(); break;
      case L:
      case UNKNOWN_L: car.left(); break;
      case R:
      case UNKNOWN_R: car.right(); break;
      case S:
      case UNKNOWN_S: car.stop(); break;
      default: break;
    }

  }
  else {
    if (millis() - preMillis > 200) {
      car.stop();
      preMillis = millis();
    }

  }

}
