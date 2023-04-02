#include "config.h"
String inputString = ""; // Definition von inputString

#include "SerGrid.h"
#include "commands.h"
#include "Mkeyb.h"
#include <Joystick.h>
#include "xJoystick.h"
#include <Mouse.h>

#include <HID.h>
//#include <UsbMscFat.h>
//#include <SdFat.h>

#ifdef OTA_HANDLER  
  #include <ArduinoOTA.h> 
#endif // OTA_HANDLER

//Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
//  JOYSTICK_TYPE_JOYSTICK, 32, 0,
//  true, true, true, true, true, true,
//  true, true, true, true, true);



void setup() {
  // Serielle Setup-Funktionen
  initSerialGrid();

  // Keyboard Setup-Funktionen
  initMkeyb();
  //Keyboard.begin();

  // Maus Setup-Funktionen
  Mouse.begin();

  // Joystick setup
  init_xJoystick();

  
  // Weitere Setup-Funktionen
}

void loop() {
  processSerialData();

    // Lesen von Befehlen von der USB-Seriellen Schnittstelle
  while (Serial.available() > 0) {
    char incomingChar = Serial.read();
    if (incomingChar == '\n') {
      processCommand(inputString);
      inputString = "";
    } else {
      inputString += incomingChar;
    }
  }

  // Weitere Loop-Funktionen
}