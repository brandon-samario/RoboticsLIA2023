const int latch = A0; // Variable to store the pin number for the latch
const int cp = 12; // Variable to store the pin number for the cp
const int data = 13; // Pin to pass the information to the shift register
const int dPins[4] = {A4, A1, A2, A5}; // Array to store the pin numbers that control the digits

const byte digits[10] = { // Array to store the patterns for displaying numbers on the 7-segment display
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B0000111,  // 7
  B01111111, // 8
  B01101111, // 9
};

void setup() {
  Serial.begin (9600); // Initialize the serial communication for debugging purposes

  // put your setup code here, to run once:
  digitalWrite(3, OUTPUT); // Set pin 3 as output
  pinMode(3, 1); // Set pin 3 as an input (HIGH impedance state)
  
  for (int i = 5 ; i < 9 ; i++) { // Set pins 5, 6, 7, 8 as outputs
    pinMode(i, OUTPUT);
  }

  // Set the pin modes for the 7 segment display
  pinMode(latch, OUTPUT);
  pinMode(cp, OUTPUT);
  pinMode(data, OUTPUT);

  pinMode(A4, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop() {
  //digit 4
  analogWrite(A4, 255); // Turn on segment A of the 7-segment display
  analogWrite(A1, 255); // Turn on segment B of the 7-segment display
  analogWrite(A2, 255); // Turn on segment C of the 7-segment display
  analogWrite(A5, 0); // Turn off segment D of the 7-segment display

  analogWrite(latch, 0); // Set the latch pin to LOW to prepare for data transfer
  shiftOut(data, cp, MSBFIRST, digits[0]); // Shift out the pattern for digit 0
  analogWrite(latch, 255); // Set the latch pin to HIGH to update the display

  delay(5); // Delay for 5 milliseconds

  //digit 3
  analogWrite(A4, 255); // Turn on segment A of the 7-segment display
  analogWrite(A1, 255); // Turn on segment B of the 7-segment display
  analogWrite(A2, 0); // Turn off segment C of the 7-segment display
  analogWrite(A5, 255); // Turn on segment D of the 7-segment display

  analogWrite(latch, 0); // Set the latch pin to LOW to prepare for data transfer
  shiftOut(data, cp, MSBFIRST, digits[2]); // Shift out the pattern for digit 2
  analogWrite(latch, 255); // Set the latch pin to HIGH to update the display

  delay(5); // Delay for 5 milliseconds

  //digit 2
  analogWrite(A4, 255); // Turn on segment A of the 7-segment display
  analogWrite(A1, 0); // Turn off segment B of the 7-segment display
  analogWrite(A2, 255); // Turn on segment C of the 7-segment display
  analogWrite(A5, 255); // Turn on segment D of the 7-segment display

  analogWrite(latch, 0); // Set the latch pin to LOW to prepare for data transfer
  shiftOut(data, cp, MSBFIRST, digits[2]); // Shift out the pattern for digit 2
  analogWrite(latch, 255); // Set the latch pin to HIGH to update the display

  delay(5); // Delay for 5 milliseconds

  //digit 1
  analogWrite(A4, 0); // Turn off segment A of the 7-segment display
  analogWrite(A1, 255); // Turn on segment B of the 7-segment display
  analogWrite(A2, 255); // Turn on segment C of the 7-segment display
  analogWrite(A5, 255); // Turn on segment D of the 7-segment display

  analogWrite(latch, 0); // Set the latch pin to LOW to prepare for data transfer
  shiftOut(data, cp, MSBFIRST, digits[0]); // Shift out the pattern for digit 0
  analogWrite(latch, 255); // Set the latch pin to HIGH to update the display

  delay(5); // Delay for 5 milliseconds
}
