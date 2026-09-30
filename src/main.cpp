#include <Arduino.h>
#include <Servo.h>

// Define Pins
#define SERVO_PIN 9

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
}

void loop() {
  myServo.write(0);
  delay(1000);
  myServo.write(180);
  delay(1000);
}