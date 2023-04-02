#include "commands.h"
#include "Mkeyb.h"
#include "xJoystick.h"

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
    // wenn der mode über seriell oder i2c oder spi gesetzt wurde, dann auf den erforderlichen geräten die Statusrückmeldung ausgeben
    String kbCommand = command.substring(3);
    processKeyboardCommand(kbCommand);
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

 void typeKeyCommand(String command) {
   if (command.startsWith("KEY ")) {
//     uint8_t key = command.substring(4).toInt();
//     Keyboard.press(key);
     delay(10);
//     Keyboard.release(key);
   } else if (command.startsWith("STRING ")) {
     String str = command.substring(7);
//     Keyboard.print(str);
   }
 }


void processKeyboardCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Tastaturbefehlen
      if (command.startsWith("setLayout ")) {
      String layout = command.substring(10);
      setLayoutCommand(layout);
    } else if (command.startsWith("KEY ")) {
      //typeKeyCommand(command);
    } else if (command.startsWith("STRING ")) {
      //typeKeyCommand(command);
    }

}
void processKeyboardCommandStreams(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Tastaturbefehls Streams
      if (command.startsWith("setLayout ")) {
      String layout = command.substring(10);
      setLayoutCommand(layout);
    } else if (command.startsWith("KEY ") || command.startsWith("STRING ")) {
      //typeKeyCommand(command);
    }

}

void processMouseCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Mausbefehlen

}
void processMouseCommandStream(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von Mausbefehls Streams

}



void processSerialCommand(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von seriellen Befehlen

}
void processSerialCommandStream(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von seriellen Befehls Streams

}


void processEsp32Command(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von ESP32-Befehlen
}
void processEsp32CommandStream(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von ESP32-Befehls Streams
}

void processEsp32Serial(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von ESP32-Serial-Befehlen
}
void processEsp32SerialStream(String command) {
  // Implementieren Sie die Funktion zur Verarbeitung von ESP32-Serial Streams
}
void setCommandMode(String mode) {
  currentCommandMode = mode;
}

String getCommandMode() {
  return currentCommandMode;
}

