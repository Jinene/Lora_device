#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2

#define BAND 868E6

int packetCounter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Transmitter Starting...");

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(BAND)) {
    Serial.println("LoRa init failed!");
    while (1);
  }

  // Advanced radio parameters
  LoRa.setSpreadingFactor(7);     // SF7 (faster, less range)
  LoRa.setSignalBandwidth(125E3); // 125 kHz
  LoRa.setCodingRate4(5);         // 4/5 coding rate
  LoRa.enableCrc();

  Serial.println("LoRa Initialized Successfully");
}

void loop() {
  float fakeTemperature = 25.0 + random(-10, 10) * 0.1;

  String payload = "{";
  payload += "\"id\":1,";
  payload += "\"temp\":" + String(fakeTemperature, 2) + ",";
  payload += "\"count\":" + String(packetCounter);
  payload += "}";

  Serial.println("Sending: " + payload);

  LoRa.beginPacket();
  LoRa.print(payload);
  LoRa.endPacket();

  packetCounter++;

  delay(5000);
}
