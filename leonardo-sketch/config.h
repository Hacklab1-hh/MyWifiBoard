#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// die Config für die Seriellen Schnittstellen definieren
#define BAUD_RATE0 115200 // Baudrate für die serielle USB Kommunikation
#define BAUD_RATE1 115200 // Baudrate für die serielle RX0/TX0 Kommunikation
#define SERIAL1_RX_PIN 0 // RX-Pin für die Hardware-Serielle Schnittstelle (Serial1)
#define SERIAL1_TX_PIN 1 // TX-Pin für die Hardware-Serielle Schnittstelle (Serial1)
#define SOFTWARE_SERIAL_RX_PIN 2 // RX-Pin für die Software-Serielle Schnittstelle
#define SOFTWARE_SERIAL_TX_PIN 3 // TX-Pin für die Software-Serielle Schnittstelle

// Definitionen für die serial0
#define BUFFER_SIZE0 128 // Puffergröße für Befehle
#define COMMAND_DELAY0 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die Serial1
#define BUFFER_SIZE1 128 // Puffergröße für Befehle
#define COMMAND_DELAY1 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die SerialBT
#define BUFFER_SIZE2 128 // Puffergröße für Befehle
#define COMMAND_DELAY2 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die SerialNRF
#define BUFFER_SIZE3 128 // Puffergröße für Befehle
#define COMMAND_DELAY3 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die SerialMaus
#define BUFFER_SIZE4 128 // Puffergröße für Befehle
#define COMMAND_DELAY4 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die SerialKeyboard
#define BUFFER_SIZE5 128 // Puffergröße für Befehle
#define COMMAND_DELAY5 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die SerialJoystick
#define BUFFER_SIZE6 128 // Puffergröße für Befehle
#define COMMAND_DELAY6 10 // Verzögerung zwischen Befehlen in Millisekunden

// Definitionen für die SerialSerial
#define BUFFER_SIZE7 128 // Puffergröße für Befehle
#define COMMAND_DELAY7 10 // Verzögerung zwischen Befehlen in Millisekunden


// definieren des OTA-Handlers
//#define OTA_HANDLER  // soll der OTA-HAndler verwendet werden?

// Basiselemente für die Verarbeitung der empfangenen Commands festlegen
const int CS_PIN = 10; // Chip-Select-Pin für die SD-Karte
const int CS_PIN1 = 11; // Chip-Select-Pin für den NRF24_2
const int CS_PIN2 = 11; // Chip-Select-Pin für den esp01s1

// wenn der Leonardo im Einsatz ist
const int CS_PIN3 = 12; // Chip-Select-Pin für den flipper als Master

// wenn der ESP32 im Einsatz ist
const int CS_PIN4 = 13; // Chip-Select-Pin für den cc1101 (433)
const int CS_PIN5 = 14; // Chip-Select-Pin für den cc1101 (868)
const int CS_PIN6 = 15; // Chip-Select-Pin für den cc1101 (915)

// generelles zur datenübertragung auf dem seriellen Bus
const char CMD_SEPARATOR = ';'; // Trennzeichen für Befehle
extern String inputString; // String zum Speichern der empfangenen Befehle

#define SERIAL0 0
#define SERIAL1 1

#define LEONARDO 0
#define ESP32 1
#define NRF24_1 2
#define NRF24_1 3
#define ESP01s1 4
#define ESP01s2 5

#endif // CONFIG_H
