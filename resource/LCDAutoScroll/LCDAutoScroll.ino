#include<LiquidCrystal.h>

#define LCD_COLS 16

LiquidCrystal lcd(3, A1, 2, A4, A2, A5, A3); //2, A1, 3, A2, A3, A4, A5 
/*LiquidCrystal(rs(4), rw(5), enable(6), d4(11), d5(12), d6(13), d7(14))
 * = ( 4, 5, 6, 11, 12, 13, 14) in LCD 
 */

String lcdStr = "hello hoge humu nyann nyann ";
int lcdStrStartPosition = 0;

void setup() {
  lcd.begin(LCD_COLS, 2);
}

void loop() {
  for (int i = 0; i < LCD_COLS; i++) {
    lcd.setCursor(i, 0);
    int tempPos = i + lcdStrStartPosition;
    if (tempPos >= lcdStr.length()) tempPos = tempPos - lcdStr.length();
    lcd.print(lcdStr.charAt(tempPos));
  }
  lcdStrStartPosition++;
  if (lcdStrStartPosition >= lcdStr.length()) lcdStrStartPosition = 0;
  delay(200);
}
