
#include "Mkeyb.h"
#include "config.h"
#include <Keyboard.h>




//#define DEFAULT_LAYOUT 0

// Standard-Tastaturlayout:
uint8_t currentLayout = DEFAULT_LAYOUT;

void initMkeyb() {
  Keyboard.begin();
}

void setMkeybLayout(uint8_t layout) {
  currentLayout = layout;
  // Weitere Initialisierung und Anpassung des Tastaturlayouts
}

void sendMkeybPress(char key) {
  // Tastendruck entsprechend dem aktuellen Tastaturlayout senden
  Keyboard.press(key);
}

void sendMkeybRelease(char key) {
  // Tastenfreigabe entsprechend dem aktuellen Tastaturlayout senden
  Keyboard.release(key);
}
