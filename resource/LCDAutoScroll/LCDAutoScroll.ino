<<<<<<< HEAD
#include "lcd.h"

=======
#include<LiquidCrystal.h>
>>>>>>> parent of 637db65... try to add lcd

#define LCD_RS_PIN 3
#define LCD_RW_PIN A1
#define LCD_ENABLE_PIN 2
#define LCD_D4_PIN A4
#define LCD_D5_PIN A2
#define LCD_D6_PIN A5
#define LCD_D7_PIN A3

MyLCD mylcd((int)LCD_RS_PIN, (int)LCD_RW_PIN, (int)LCD_ENABLE_PIN, (int)LCD_D4_PIN, (int)LCD_D5_PIN, (int)LCD_D6_PIN, (int)LCD_D7_PIN);
//LiquidCrystal lcd(LCD_RS_PIN, LCD_RW_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
/*LiquidCrystal(rs(4), rw(5), enable(6), d4(11), d5(12), d6(13), d7(14))
   = ( 4, 5, 6, 11, 12, 13, 14) in LCD
*/

void setup() {
  mylcd.initialize();
}

void loop() {
  mylcd.scroll();
}
