#include "config.h"
#include "commands.h"
#include "SerGrid.h"
#include <SoftwareSerial.h>

// #ifdef BLUETOOTH
// #include <BluetoothSerial.h>
// BluetoothSerial SerialBT; 
// #endif

// #ifdef OTA_HANDLER  
// #include <ArduinoOTA.h> 
// #endif // OTA_HANDLER

// HardwareSerial &serial1 = Serial1;

// SoftwareSerial softSerial(SOFTWARE_SERIAL_RX_PIN, SOFTWARE_SERIAL_TX_PIN);

// HardwareSerial Serial_two(1);
// HardwareSerial* serials[NUM_COM] = {&Serial, &Serial_two };

// uint8_t buf1[NUM_COM][bufferSize];
// uint16_t i1[NUM_COM]={0,0,0};

// uint8_t buf2[NUM_COM][bufferSize];
// uint16_t i2[NUM_COM]={0,0,0};

// uint8_t BTbuf[bufferSize];
// uint16_t iBT =0;


void initSerialGrid() {
  Serial.begin(BAUD_RATE);
  //Serial0.begin(BAUD_RATE);
  Serial1.begin(BAUD_RATE);
  //softSerial.begin(BAUD_RATE);
}

// void initSerialGrid2() {
//   delay(500);
  
//   COM[0]->begin(UART_BAUD0, SERIAL_PARAM0, SERIAL0_RXPIN, SERIAL0_TXPIN);
//   COM[1]->begin(UART_BAUD1, SERIAL_PARAM1, SERIAL1_RXPIN, SERIAL1_TXPIN);
//   COM[2]->begin(UART_BAUD2, SERIAL_PARAM2, SERIAL2_RXPIN, SERIAL2_TXPIN);


// }

void processSerialData() {
  // Funktion zum Verarbeiten von Daten zwischen den seriellen Schnittstellen
  // Zum Beispiel: Lesen von Daten von Serial, Serial1 und softSerial und weiterleiten an die entsprechenden Schnittstellen
  // due USB-Serial-Scnittstelle
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    processSerialCommand(command);
  }
  // die erste Hardware-Serial RX0/TX0
  // if (serial0.available()) {
  //   String command = Serial0.readStringUntil('\n');
  //   processEsp32Command(command);
  // }
  // die zweite Hardware-Serial RX1/TX1
  if (Serial1.available()) {
    String command = Serial1.readStringUntil('\n');
    processEsp32Command(command);
  }
}

// void processSerialData() {
//   static uint32_t startTime = millis();
//   while (millis() - startTime < COMMAND_DELAY) {
//     for (uint8_t i = 0; i < numSerials; ++i) {
//       if (serials[i]->available()) {
//         String command = serials[i]->readStringUntil('\n');
//         command.trim();
//         if (command.length() > 0) {
//           processSerialCommand(command);
//         }
//       }
//     }
//   }
// }
