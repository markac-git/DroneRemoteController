#include <Arduino.h>
#include <Joystick.h>
#include "Network.h"
#include "Button.h"
//const char * password = "";

// Instantiating objects
Joystick joystickLeft = Joystick(36, 39, 15); 
Joystick joystickRight = Joystick(34, 35, 23); 
Network network = Network();

void controllerLeft(Joystick &joystick){
  //Serial.prints are for partition testing
  if(joystick.getJoystickValues().first>1000 && joystick.getJoystickValues().second > 4000){
      Serial.println("L: Right");
      network.sendMessage("right20");
    } else if (joystick.getJoystickValues().first > 1000 && joystick.getJoystickValues().second == 0){
      Serial.println("L: Left");
      network.sendMessage("left20");
    } else if (joystick.getJoystickValues().first > 4000 && joystick.getJoystickValues().second > 1000){
      Serial.println("L: Forward");
      network.sendMessage("forward20");
    } else if (joystick.getJoystickValues().first == 0 && joystick.getJoystickValues().second > 1000){
      Serial.println("L: Back");
      network.sendMessage("back20");
    }

    if(joystick.isButtonPressed()){
        Serial.println("L: Button Pressed");
        network.sendMessage("takeoff");
      }
  }

    void controllerRight(Joystick &joystick){
      if (joystick.getJoystickValues().first > 1000 && joystick.getJoystickValues().second > 4000){
        Serial.println("R: Right");
        network.sendMessage("battery");
      } else if (joystick.getJoystickValues().first > 1000 && joystick.getJoystickValues().second == 0){
        Serial.println("R: Left");
      } else if (joystick.getJoystickValues().first > 4000 && joystick.getJoystickValues().second > 1000){
        Serial.println("R: Forward");
        network.sendMessage("up20");
      } else if (joystick.getJoystickValues().first == 0 && joystick.getJoystickValues().second > 1000){
        Serial.println("R: Back");
        network.sendMessage("down20");
      }

      if(joystick.isButtonPressed()){
        Serial.println("R: Button Pressed");
        network.sendMessage("land");
      }
    }

    void setup(){
      Serial.begin(9600);
      network.init();
    }

    void loop(){
        controllerLeft(joystickLeft);
        controllerRight(joystickRight);
        delay(500); //so that our emulator doens't get to many commands at the same time
      }
      //TESTING joystickLeft.printJoystickValues(joystickLeft);
      //
      
      