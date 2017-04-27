#include<LiquidCrystal.h>
#define LCD_COLS 16
#define LCD_RS_PIN 3
#define LCD_RW_PIN A1
#define LCD_ENABLE_PIN 2
#define LCD_D4_PIN A4
#define LCD_D5_PIN A2
#define LCD_D6_PIN A5
#define LCD_D7_PIN A3
String lcdStr;
int lcdStrStartPosition;
LiquidCrystal lcd(LCD_RS_PIN, LCD_RW_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
/*LiquidCrystal(rs(4), rw(5), enable(6), d4(11), d5(12), d6(13), d7(14))
   = ( 4, 5, 6, 11, 12, 13, 14) in LCD
*/

void setup() {
  lcd.begin(LCD_COLS, 2);
  lcdStr = "hello hoge humu nyann nyann ";
  lcdStrStartPosition = 0;
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
