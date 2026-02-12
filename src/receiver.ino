#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2

#define BAND 868E6

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Receiver Starting...");

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(BAND)) {
    Serial.println("LoRa init failed!");
    while (1);
  }

  LoRa.setSpreadingFactor(7);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);
  LoRa.enableCrc();

  Serial.println("LoRa Initialized Successfully");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";

    while (LoRa.available()) {
      received += (char)LoRa.read();
    }

    int rssi = LoRa.packetRssi();
    float snr = LoRa.packetSnr();

    Serial.println("Received Packet:");
    Serial.println(received);
    Serial.print("RSSI: ");
    Serial.println(rssi);
    Serial.print("SNR: ");
    Serial.println(snr);
    Serial.println("------------------------");
  }
}
