#ifndef COMMANDS_H
#define COMMANDS_H

#include <Arduino.h>

//void processCommand(String command, Stream &source);
void processCommand(String command);
void processSerialCommand(String command);
void processEsp32Command(String command);

void setLayoutCommand(String layout);
void processKeyboardCommand(String command);
void processMouseCommand(String command);

void processJoystickCommand(String command);
void setCommandMode(String mode);
String getCommandMode();

// Befehlsmodi
#define CM_RES "CM_RES"
#define CM_STAT "CM_STAT"

#endif // COMMANDS_H
