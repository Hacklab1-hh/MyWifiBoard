#include <TinyWire.h>
#include <DigiKeyboard.h>
#include <SoftwareSerial.h>

#define I2C_ADDRESS 0x08
#define RX_PIN 1
#define TX_PIN 0
#define BAUD_RATE 9600

SoftwareSerial softSerial(RX_PIN, TX_PIN);

void setup() {
  DigiKeyboard.update();
  softSerial.begin(BAUD_RATE);
  TinyWire.begin(I2C_ADDRESS);
}

void loop() {
  if (DigiKeyboard.available()) {
    String inputString = "";
    while (DigiKeyboard.available()) {
      char inputChar = DigiKeyboard.read();
      inputString += inputChar;
    }
    if (inputString.startsWith("KB")) {
      inputString.remove(0, 2);
      DigiKeyboard.sendKeyStroke(inputString.c_str());
    } else {
      softSerial.print(inputString);
    }
  }
  while (softSerial.available()) {
    char inputChar = softSerial.read();
    DigiKeyboard.print(inputChar);
  }
}
