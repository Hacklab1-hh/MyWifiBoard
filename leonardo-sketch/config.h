#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// die Config für die Seriellen Schnittstellen definieren
#define BAUD_RATE 115200 // Baudrate für die serielle Kommunikation
#define SERIAL1_RX_PIN 0 // RX-Pin für die Hardware-Serielle Schnittstelle (Serial1)
#define SERIAL1_TX_PIN 1 // TX-Pin für die Hardware-Serielle Schnittstelle (Serial1)
#define SOFTWARE_SERIAL_RX_PIN 2 // RX-Pin für die Software-Serielle Schnittstelle
#define SOFTWARE_SERIAL_TX_PIN 3 // TX-Pin für die Software-Serielle Schnittstelle

// Definitionen für die WiFiDuck Keyboard-Implementierung
#define BUFFER_SIZE 128 // Puffergröße für Befehle
#define COMMAND_DELAY 10 // Verzögerung zwischen Befehlen in Millisekunden

// Basiselemente für die Verarbeitung der empfangenen Commands festlegen
const int CS_PIN = 10; // Chip-Select-Pin für die SD-Karte
const char CMD_SEPARATOR = ';'; // Trennzeichen für Befehle
extern String inputString; // String zum Speichern der empfangenen Befehle

#endif // CONFIG_H
