#include "lcd.h"
#define LCD_RS_PIN 3
#define LCD_RW_PIN A1
#define LCD_ENABLE_PIN 2
#define LCD_D4_PIN A4
#define LCD_D5_PIN A2
#define LCD_D6_PIN A5
#define LCD_D7_PIN A3
MyLCD lcd(LCD_RS_PIN, LCD_RW_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void setup() {
  lcd.initialize();
  lcd.updateString("hogehogedayo ", 0);
  lcd.updateString("munyamunyadayo ", 1);
}

void loop() {
  lcd.scroll(300);
}
