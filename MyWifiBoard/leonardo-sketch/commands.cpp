#include "commands.h"
#include "Mkeyb.h"

String currentCommandMode = "";


//void processCommand(String command, Stream &source) {
void processCommand(String command) {
  // Verarbeiten der empfangenen Befehle und Ausführen der entsprechenden Aktionen
  if (command.startsWith("setLayout ")) {
    String layout = command.substring(10);
    setLayoutCommand(layout);
  } else if (command.startsWith("KB ")) {
    String kbCommand = command.substring(3);
    processKeyboardCommand(kbCommand);
  } else if (command.startsWith("MS ")) {
    String msCommand = command.substring(3);
    processMouseCommand(msCommand);
  } else if (command.startsWith("JS ")) {
    String jsCommand = command.substring(3);
    processJoystickCommand(jsCommand);
  } else if (command.startsWith("SER ")) {
    String serCommand = command.substring(4);
    processSerialCommand(serCommand);
  } else if (command.startsWith("ESP32 ")) {
    String esp32Command = command.substring(6);
    processEsp32Command(esp32Command);
  } else if (command == CM_RES) {
    currentCommandMode = "";
  } else if (command == CM_STAT) {
    Serial.println(getCommandMode());
  } else if (currentCommandMode == "KB") {
    if (command.startsWith("setLayout ")) {
      String layout = command.substring(10);
      setLayoutCommand(layout);
    } else if (command.startsWith("KEY ") || command.startsWith("STRING ")) {
      //typeKeyCommand(command);
    }
  } else {
    setCommandMode(command);
  }
}

void setLayoutCommand(String layout) {
  if (layout == "US_ENGLISH") {
    setMkeybLayout(LAYOUT_US_ENGLISH);
  } else if (layout == "GERMAN") {
    setMkeybLayout(LAYOUT_GERMAN);
  } else if (layout == "FRENCH") {
    setMkeybLayout(LAYOUT_FRENCH);
  }
  // Weitere Layouts hinzufügen
}

// void typeKeyCommand(String command) {
//   if (command.startsWith("KEY ")) {
//     uint8_t key = command.substring(4).toInt();
//     Keyboard.press(key);
//     delay(10);
//     Keyboard.release(key);
//   } else if (command.startsWith("STRING ")) {
//     String str = command.substring(7);
//     Keyboard.print(str);
//   }
// }


void processKeyboardCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Tastaturbefehlen
}

void processMouseCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Mausbefehlen
}

void processJoystickCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Joystickbefehlen
}

void processSerialCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von seriellen Befehlen
}

void processEsp32Command(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von ESP32-Befehlen
}

void setCommandMode(String mode) {
  currentCommandMode = mode;
}

String getCommandMode() {
  return currentCommandMode;
}

