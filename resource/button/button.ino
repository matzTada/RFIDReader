#include "button.h"

#define BUTTON_1_PIN 4
#define BUTTON_2_PIN 5
#define BUTTON_3_PIN 6
#define BUTTON_4_PIN 7

Buttons buttons = Buttons(BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN, BUTTON_4_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttons.updateLastButtonNumber();
  Serial.println(buttons.lastButtonNumber);
}
