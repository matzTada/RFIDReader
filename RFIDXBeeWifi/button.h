#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class Buttons {
  public:
    int lastButtonNumber;
    int pins[4];
    Buttons(int pin1, int pin2, int pin3, int pin4);
    boolean updateLastButtonNumber();
};

#endif
