#ifndef LCD_H
#define LCD_H

#include "Arduino.h"

#include<LiquidCrystal.h>
#define LCD_COLS 16

class MyLCD : public LiquidCrystal {
  public:
    String lcdStr;
    int lcdStrStartPosition;

    MyLCD(int a, int b, int c, int d, int e, int f, int g);

    void initialize();
    void scroll();
};

#endif
