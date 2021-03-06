#include "button.h"

Buttons::Buttons(int pin1, int pin2, int pin3, int pin4) {
  lastButtonNumber = 0;
  pins[0] = pin1;
  pins[1] = pin2;
  pins[2] = pin3;
  pins[3] = pin4;
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) pinMode(pins[i], INPUT_PULLUP);
}

boolean Buttons::updateLastButtonNumber() {
  boolean pushedFlag = false;
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    if (digitalRead(pins[i]) == LOW) { //CAUTION!! INPUT_PULLUP is used!
      lastButtonNumber = i;
      pushedFlag = true;
    }
  }
  return pushedFlag;
}

