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

void loop() {
  receiveUPD();

  // delay (1000);
  // sendUPD("a");
  // delay(1000);
  // sendUPD("b");
  // delay(1000);
  // sendUPD("c");

}


String receiveUPD(){
  int packetSize = udp.parsePacket();
  if (packetSize > 0){
    char incomingPacket[255];
    int len = udp.read(incomingPacket, 255);
    String message = String(incomingPacket);
    Serial.println("recieved msg: " + message);
    return message;
  } else{
    return "";
  }
}


void sendUPD(String message) {
  udp.beginPacket(udpAddress, udpSenderPort);
  udp.write((const uint8_t *)message.c_str(), message.length());
  udp.endPacket();
  Serial.println("Sent: " + message);
}