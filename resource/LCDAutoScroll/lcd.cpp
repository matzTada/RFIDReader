#include "lcd.h"

MyLCD::MyLCD(int a, int b, int c, int d, int e, int f, int g) : LiquidCrystal(a, b, c, d, e, f, g) {
  //引数があるコンストラクタはこうやれば呼び出せる！引数を書いてあげるのか。
  /*LiquidCrystal(rs(4), rw(5), enable(6), d4(11), d5(12), d6(13), d7(14))  = ( 4, 5, 6, 11, 12, 13, 14) in LCD*/
}

void MyLCD::initialize() {
  begin(LCD_COLS, 2);
  str1 = "Hello. This is LCD display. ";
  str2 = "Here is for str2. ";
  str1Pos = 0;
  str2Pos = 0;
  pastMillis = millis();
}

void MyLCD::scroll(long interval) {
  if (millis() - pastMillis < interval) return;
  pastMillis = millis();
  for (int i = 0; i < LCD_COLS; i++) {
    int tempPos;
    setCursor(i, 0);
    tempPos = i + str1Pos;
    if (tempPos >= str1.length()) tempPos = tempPos - str1.length();
    print(str1.charAt(tempPos));

    setCursor(i, 1);
    tempPos = i + str2Pos;
    if (tempPos >= str2.length()) tempPos = tempPos - str2.length();
    print(str2.charAt(tempPos));
  }

  str1Pos++;
  if (str1Pos >= str1.length()) str1Pos = 0;
  str2Pos++;
  if (str2Pos >= str2.length()) str2Pos = 0;
}

void MyLCD::updateString(String str, int line) {
  if (line == 0) {
    str1 = str;
    str1Pos = 0;
  } else if (line == 1) {
    str2 = str;
    str2Pos = 0;
  }
  pastMillis = millis();
}
