# ESP32 LoRa Beginner Project

This project demonstrates basic LoRa communication between two ESP32 boards using SX1276 (RA-02).

## Features
- Point-to-point LoRa communication
- RSSI measurement
- ACK confirmation
- Structured packet format

## Hardware
- ESP32
- SX1276 (RA-02)
- 868 MHz antenna

## Wiring (ESP32 → SX1276)

| SX1276 | ESP32 |
|--------|-------|
| VCC    | 3.3V  |
| GND    | GND   |
| NSS    | 5     |
| RST    | 14    |
| DIO0   | 2     |
| MOSI   | 23    |
| MISO   | 19    |
| SCK    | 18    |

## Frequency
868 MHz (EU/Africa)
