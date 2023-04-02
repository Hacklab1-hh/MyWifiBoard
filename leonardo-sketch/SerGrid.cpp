#include "config.h"
#include "commands.h"
#include "SerGrid.h"
//#include <HardwareSerial.h>
#include <SoftwareSerial.h>

// #ifdef BLUETOOTH
// #include <BluetoothSerial.h>
// BluetoothSerial SerialBT; 
// #endif

// #ifdef OTA_HANDLER  
// #include <ArduinoOTA.h> 
// #endif // OTA_HANDLER

 HardwareSerial &serial1 = Serial1;

// SoftwareSerial softSerial(SOFTWARE_SERIAL_RX_PIN, SOFTWARE_SERIAL_TX_PIN);

// HardwareSerial Serial_one(1);
// HardwareSerial* serials[NUM_COM] = {&Serial, &Serial_one };

// uint8_t buf1[NUM_COM][bufferSize];
// uint16_t i1[NUM_COM]={0,0,0};

// uint8_t buf2[NUM_COM][bufferSize];
// uint16_t i2[NUM_COM]={0,0,0};

// uint8_t BTbuf[bufferSize];
// uint16_t iBT =0;
//HardwareSerial Serial1(1); // initialisiere serielle Schnittstelle 1 (RX: GPIO3, TX: GPIO1)
//HardwareSerial Serial2(2); // initialisiere serielle Schnittstelle 2 (RX: GPIO16, TX: GPIO17)

//Serial* serialPorts[] = {&Serial, &Serial1};
//const int SERIAL_PORT_COUNT = sizeof(serialPorts) / sizeof(Serial*);


void initSerialGrid() {
  Serial.begin(BAUD_RATE0);
  Serial1.begin(BAUD_RATE1);
  //Serial1.begin(BAUD_RATE);
  //softSerial.begin(BAUD_RATE);
    // Serielle Schnittstellen initialisieren
  // for (int i = 0; i < SERIAL_PORT_COUNT; i++) {
  //   serialPorts[i]->begin(BAUD_RATE);
  // }

}

// void initSerialGrid2() {
//   delay(500);
  
//   COM[0]->begin(BAUD_RATE0, SERIAL_PARAM0, SERIAL0_RXPIN, SERIAL0_TXPIN);
//   COM[1]->begin(BAUD_RATE1, SERIAL_PARAM1, SERIAL1_RXPIN, SERIAL1_TXPIN);
//   COM[2]->begin(BAUD_RATE2, SERIAL_PARAM2, SERIAL2_RXPIN, SERIAL2_TXPIN);


// }

void processSerialData() {
  // Funktion zum Verarbeiten von Daten zwischen den seriellen Schnittstellen
  // Zum Beispiel: Lesen von Daten von Serial, Serial1 und softSerial und weiterleiten an die entsprechenden Schnittstellen
  // due USB-Serial-Scnittstelle
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    processSerialCommand(command);
  }
  // die zweite Hardware-Serial RX0/TX0
  if (Serial1.available()) {
    String command = Serial1.readStringUntil('\n');
    processEsp32Command(command);
  }

}

String  recieveSerial( int serid ) {
    
  if (serid == 0) {
    if (Serial.available()) {
      return Serial.readStringUntil('\n');
      }
  }
  if (serid == 1) {
    if (Serial1.available()) {
      return Serial1.readStringUntil('\n');
    }
  }
}

// void processSerialData1() {
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
