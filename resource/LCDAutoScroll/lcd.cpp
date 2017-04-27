#include "lcd.h"

MyLCD::MyLCD(int a, int b, int c, int d, int e, int f, int g)
  : LiquidCrystal(int a, int b, int c, int d, int e, int f, int g) {
}

void MyLCD::initialize() {
  begin(LCD_COLS, 2);
  lcdStr = "hello hoge humu nyann nyann ";
  lcdStrStartPosition = 0;
}

void MyLCD::scroll() {
  for (int i = 0; i < LCD_COLS; i++) {
    setCursor(i, 0);
    int tempPos = i + lcdStrStartPosition;
    if (tempPos >= lcdStr.length()) tempPos = tempPos - lcdStr.length();
    print(lcdStr.charAt(tempPos));
  }
  lcdStrStartPosition++;
  if (lcdStrStartPosition >= lcdStr.length()) lcdStrStartPosition = 0;
  delay(200);
}
