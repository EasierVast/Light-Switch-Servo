#include <Arduino.h>
#include <Servo.h>

// Define Pins
#define SERVO_PIN 9
#define BUTTON_PIN 2

Servo myServo;
int buttonState = LOW;

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) {
    myServo.write(180);
  }
  else if (buttonState == LOW) {
    myServo.write(0);
  }
}