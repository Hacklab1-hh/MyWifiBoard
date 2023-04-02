#ifndef XJOYSTICK_H
#define XJOYSTICK_H
#include "config.h"
#include <Arduino.h>
#include "Mkeyb.h"
#include "commands.h"

void init_xJoystick();
void processJoystickCommand(String command);
void processJoystickCommandStream(String command);
#endif //XJOYSTICK_H
