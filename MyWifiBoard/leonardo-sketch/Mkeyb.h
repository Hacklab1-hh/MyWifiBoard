#ifndef MKEYB_H
#define MKEYB_H

#include "config.h"
#include <Arduino.h>

// Tastaturlayouts definieren
#define LAYOUT_US_ENGLISH 1
#define LAYOUT_GERMAN 2
#define LAYOUT_FRENCH 3
// Weitere Tastaturlayouts hinzufügen
#define DEFAULT_LAYOUT LAYOUT_US_ENGLISH

// Funktionen
void initMkeyb();
void setMkeybLayout(uint8_t layout);
void sendMkeybPress(char key);
void sendMkeybRelease(char key);

// Externe Variablen
extern uint8_t currentLayout;

#endif // MKEYB_H
