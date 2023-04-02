#include "config.h"
#include <Arduino.h>
#include <Joystick.h>

 Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
   JOYSTICK_TYPE_JOYSTICK, 32, 0,
   true, true, true, true, true, true,
   true, true, true, true, true);

 void init_xJoystick() {
     // Joystick Setup-Funktionen

   Joystick.begin();
 }

void processJoystickCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Joystickbefehlen

}
void processJoystickCommandStream(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Joystickbefehls Streams

}
