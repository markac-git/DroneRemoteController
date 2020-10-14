#include <Arduino.h>
#include <Joystick.h>
#include "Network.h"
#include "Button.h"
#include "Led.h"
//const char * password = "";


Joystick joystickLeft = Joystick(36, 39, 15); // Instantiate object
Joystick joystickRight = Joystick(34, 35, 23); // Instantiate object
Button button = Button(22);
Network network = Network();
Led led = Led(1);

void controllerLeft(Joystick &joystick){
  if(joystick.getJoystickValues().first>1000 && joystick.getJoystickValues().second > 4000){
      Serial.println("L: Right");
      network.sendMessage("right 20");
    } else if (joystick.getJoystickValues().first > 1000 && joystick.getJoystickValues().second == 0){
      Serial.println("L: Left");
      network.sendMessage("left 20");
    } else if (joystick.getJoystickValues().first > 4000 && joystick.getJoystickValues().second > 1000){
      Serial.println("L: Forward");
      network.sendMessage("forward 20");
    } else if (joystick.getJoystickValues().first == 0 && joystick.getJoystickValues().second > 1000){
      Serial.println("L: Back");
      network.sendMessage("back 20");
    }

    if(joystick.isButtonPressed()){
        Serial.println("L: Button Pressed");
        network.sendMessage("takeoff");
        delay(5000);
      }
  }

    void controllerRight(Joystick &joystick){
      if (joystick.getJoystickValues().first > 1000 && joystick.getJoystickValues().second > 4000){
        Serial.println("R: Right");
      } else if (joystick.getJoystickValues().first > 1000 && joystick.getJoystickValues().second == 0){
        Serial.println("R: Left");
      } else if (joystick.getJoystickValues().first > 4000 && joystick.getJoystickValues().second > 1000){
        Serial.println("R: Forward");
        network.sendMessage("up 20");
      } else if (joystick.getJoystickValues().first == 0 && joystick.getJoystickValues().second > 1000){
        Serial.println("R: Back");
        network.sendMessage("down 20");
      }

      if(joystick.isButtonPressed()){
        Serial.println("R: Button Pressed");
        network.sendMessage("land");
        delay(5000);
      }
    }

    void setup()
    {
      Serial.begin(9600);
      network.init();
    }

    void loop(){
        controllerLeft(joystickLeft);
        controllerRight(joystickRight);
      }
      
      //joystickRight.printJoystickValues(joystickRight);
   
   