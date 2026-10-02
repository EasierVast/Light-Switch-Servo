#include <Arduino.h>
#include <Servo.h>

// Define Pins
#define SERVO_PIN 9
#define BUTTON_PIN 2

Servo myServo;
int buttonStateNew;
int buttonStateOld = LOW;
int servoState = LOW;
int debounceDelay = 10;

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  servoState = LOW;
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonStateNew = digitalRead(BUTTON_PIN);

  if (buttonStateOld == LOW && buttonStateNew == HIGH) {
    if (servoState == LOW) {
      myServo.write(90);
      servoState = HIGH;
    }
    else {
      myServo.write(0);
      servoState = LOW;
    }
  }
  buttonStateOld = buttonStateNew;
  delay(debounceDelay);

}