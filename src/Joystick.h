#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"
#include "Button.h"

class Joystick {
public:
  Joystick(int xPin, int yPin, int buttonPin) {
    // Assign values for potentiometers
    this->xPin = xPin;
    this->yPin = yPin;
    detectCenterPosition();

    button = new Button(buttonPin);
  };

  void setName(String s) { this->name = s; }

  std::pair<int, int> getJoystickValues() {
    int xVal = analogRead(this->xPin);
    int yVal = analogRead(this->yPin);
    return std::make_pair(xVal, yVal);
  }

  bool isInDeadzone() {
    int offset = 60;
    auto joystick = getJoystickValues();

    return std::abs(joystick.first - joyXCenterVal) < offset &&
           std::abs(joystick.second - joyYCenterVal) < offset;
  }

  bool isButtonPressed() { return button->isPressed(); };

  void printJoystickValues(Joystick &joystick) {
  Serial.print("Button state: ");
  Serial.print(joystick.isButtonPressed());
  if (joystick.isInDeadzone() == false) {
    Serial.print(" , X ");
    Serial.print(joystick.getJoystickValues().first);
    Serial.print(" , y ");
    Serial.print(joystick.getJoystickValues().second);
  }
  Serial.println();
}

private:
  void detectCenterPosition() {
    auto joystick = getJoystickValues();
    joyXCenterVal = joystick.first;
    joyYCenterVal = joystick.second;
  };

  Button *button;

  int xPin = 0;
  int yPin = 0;
  int buttonPin = 0;
  int joyXCenterVal = 0;
  int joyYCenterVal = 0;
  String name = "";
};

#endif