//WIFI
#define Network_h
#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"

//const char * ssid = "TELLO-FE3279";
//const char * password = "";

const char * ssid = "TP-LINK_8C47";
const char * password = "";

AsyncUDP udp;

class Network {
public:
    Network(){      
}

void sendMessage(String msg){
  udp.writeTo((const uint8_t *)msg.c_str(), msg.length(),
              IPAddress(192, 168, 0, 103), 7000);
}


void init(){
    Serial.println("Initializing WiFi Connection ...");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed");
    delay(5000);
    init(); //recursion
  } else {
    Serial.println("WiFi Connected");
    sendMessage("command");
    }
  
  /*
    if (udp.listen(8889)) {
    Serial.print("UDP Listening on IP: ");
    Serial.println(WiFi.localIP());
    udp.onPacket([](AsyncUDPPacket packet) {
      Serial.print("UDP Packet Type: ");
      Serial.print(packet.isBroadcast()
                       ? "Broadcast"
                       : packet.isMulticast() ? "Multicast" : "Unicast");
      Serial.print(", From: ");
      Serial.print(packet.remoteIP());
      Serial.print(":");
      Serial.print(packet.remotePort());
      Serial.print(", To: ");
      Serial.print(packet.localIP());
      Serial.print(":");
      Serial.print(packet.localPort());
      Serial.print(", Length: ");
      Serial.print(packet.length());
      Serial.print(", Data: ");
      Serial.write(packet.data(), packet.length());
      Serial.println();

      // reply to the client/sender
      packet.printf("Got %u bytes of data", packet.length());
    });
  }*/
}
};


