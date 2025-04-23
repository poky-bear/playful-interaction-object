#include "WiFi.h"
#include "Secret.h"



WiFiUDP udp;
const char *udpAddress = "192.168.1.2";
const int udpSenderPort = 5006;
const int udpReceiverPort = 5005;

String sentMessage;
String receivedMessage;

void setup() {
  // (Optional)Press reset button
  // on the dev board to see these print statements

  Serial.begin(115200);
  initUDP();
}

void initUDP() {
  WiFi.begin(ssid, pass);
  Serial.println("Connecting to wifi");

  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }

  udp.begin(udpReceiverPort);
  Serial.println("UDP Initialized");

}

void loop() {}
