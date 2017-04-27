#ifndef LCD_H
#define LCD_H

#include "Arduino.h"
#include<LiquidCrystal.h>
#define LCD_COLS 16

class MyLCD : public LiquidCrystal {
  public:
    String str1;
    String str2;
    int str1Pos;
    int str2Pos;
    unsigned long pastMillis;
    MyLCD(int a, int b, int c, int d, int e, int f, int g);
    void initialize();
    void scroll(long interval);
    void updateString(String str, int line);
};
#endif

