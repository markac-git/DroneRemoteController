#include <Arduino.h>

class Led
{
    int ledPin;
public:
    Led(int pin) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
}

void turnOn(){
    digitalWrite(ledPin, HIGH);
}
void turnOff(){
    digitalWrite(ledPin, LOW);
}
};