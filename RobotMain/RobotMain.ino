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

Servo myservo; // Create an instance of the Servo class for controlling a servo motor
Ultrasonic ultrasonic(trigPin, echoPin); // Create an instance of the Ultrasonic class for the HC-SR04 sensor
Motor motor1(motorPin1, motorPin2, speedPin1, speedPin2); // Create an instance of the Motor class for motor 1
Motor motor2(motorPin2, motorPin1, speedPin2, speedPin1); // Create an instance of the Motor class for motor 2

LineTracking robot; // Create an instance of the LineTracking class
IRrecv irrecv (9); // Create an instance of the IRrecv class for receiving IR signals
decode_results results; // Create a variable to store the decoded IR signal
RobotCar car(7, 8, 5, 6, 3); // Create an instance of the RobotCar class with specified pins

void setup() {
  pinMode(3, OUTPUT); // Set pin 3 as output
  digitalWrite(3, HIGH); // Set pin 3 to high (assuming it controls some external device)
  Serial.begin(9600); // Initialize the serial communication

  // Servo setup
  myservo.attach(10); // Attach the servo to pin 10
  myservo.write(70); // Set the initial position of the servo

  // Motor setup
  motor1.stop(); // Stop motor 1
  motor2.stop(); // Stop motor 2

  // Line tracking setup
  robot.setup(); // Initialize the line tracking sensors

  // IR receiver setup
  car.init(); // Initialize the RobotCar object
  irrecv.enableIRIn(); // Enable IR reception
}

void loop() {
  // Ultrasonic sensor and motor control
  myservo.write(70); // Set the servo to the middle position
  delay(500); // Delay for 500 milliseconds
  middleDist = ultrasonic.getDistance(); // Get the distance measured by the ultrasonic sensor

  if (middleDist <= 30) { // If the middle distance is less than or equal to 30
    motor1.stop(); // Stop motor 1
    motor2.stop(); // Stop motor 2
    delay(500); // Delay for 500 milliseconds

    // Move servo to the right to check distance
    myservo.write(-20); // Set the servo to a position for checking distance to the right
    delay(1000); // Delay for 1000 milliseconds
    rightDist = ultrasonic.getDistance(); // Get the distance measured by the ultrasonic sensor

    // Move servo to the middle
    myservo.write(70); // Set the servo to the middle position
    delay(500); // Delay for 500 milliseconds

    // Move servo to the left to check distance
    myservo.write(160); // Set the servo to a position for checking distance to the left
    delay(1000); // Delay for 1000 milliseconds
    leftDist = ultrasonic.getDistance(); // Get the distance measured by the ultrasonic sensor

    // Move servo back to the middle
    myservo.write(70); // Set the servo to the middle position
    delay(500); // Delay for 500 milliseconds

    if (rightDist > leftDist) { // If the distance to the right is greater than the distance to the left
      motor2.right(); // Turn motor 2 to the right
      delay(300); // Delay for 300 milliseconds
    } else if (leftDist > rightDist) { // If the distance to the left is greater than the distance to the right
      motor1.left(); // Turn motor 1 to the left
      delay(300); // Delay for 300 milliseconds
    } else if ((rightDist <= 30) || (leftDist <= 30)) { // If either the distance to the right or left is less than or equal to 30
      motor1.backward(); // Move motor 1 backward
      motor2.backward(); // Move motor 2 backward
      delay(300); // Delay for 300 milliseconds
    } else { // If none of the above conditions are met
      motor1.forward(); // Move motor 1 forward
      motor2.forward(); // Move motor 2 forward
    }
  } else { // If the middle distance is greater than 30
    motor1.forward(); // Move motor 1 forward
    motor2.forward(); // Move motor 2 forward
  }

  // Line tracking
  robot.move(); // Move the robot based on the line tracking sensors

  // IR remote control
  if (irrecv.decode(&results)) { // If an IR signal is received and successfully decoded
    preMillis = millis(); // Record the current time
    irrecv.resume(); // Receive the next value
    switch (results.value) {
      case F:
      case UNKNOWN_F: car.forward(); break; // If the received signal is forward, move the car forward
      case B:
      case UNKNOWN_B: car.backward(); break; // If the received signal is backward, move the car backward
      case L:
      case UNKNOWN_L: car.left(); break; // If the received signal is left, turn the car left
      case R:
      case UNKNOWN_R: car.right(); break; // If the received signal is right, turn the car right
      case S:
      case UNKNOWN_S: car.stop(); break; // If the received signal is stop, stop the car
      default: break;
    }
  } else { // If no IR signal is received
    if (millis() - preMillis > 200) { // If more than 200 milliseconds have passed since the last received signal
      car.stop(); // Stop the car
      preMillis = millis(); // Record the current time
    }
  }
}
