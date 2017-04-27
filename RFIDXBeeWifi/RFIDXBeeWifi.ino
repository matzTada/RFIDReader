/*
   RFID reader based on this example https://github.com/miguelbalboa/rfid
   2017/4/15 Modified by TadaMatz
   Tell card id beased on UID
   RGB LED is optional

   2017/4/21 Modified by TadaMatz
   Delete RGB
   Add Piezzo Speaker
*/

#define PACKET_PREFIX_RRN "RRN" //RFID reader Node

//RFID reader
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN        10         // Configurable, take a unused pin, only HIGH/LOW required, must be diffrent to SS 2
MFRC522 mfrc522;   // Create MFRC522 instance.

//speaker
#include "speaker.h"
#define SPEAKER_PIN 8

//buttons
#include "button.h"
#define BUTTON_1_PIN 4
#define BUTTON_2_PIN 5
#define BUTTON_3_PIN 6
#define BUTTON_4_PIN 7
Buttons buttons = Buttons(BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN, BUTTON_4_PIN);

//LCD
#include "lcd.h"
#define LCD_RS_PIN 3
#define LCD_RW_PIN A1
#define LCD_ENABLE_PIN 2
#define LCD_D4_PIN A4
#define LCD_D5_PIN A2
#define LCD_D6_PIN A5
#define LCD_D7_PIN A3
MyLCD lcd(LCD_RS_PIN, LCD_RW_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

////Software Serial connection (connected to XBee Wifi)
//#include <SoftwareSerial.h>
//SoftwareSerial ssXBee(2, 3);

/**
   Initialize.
*/
void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC

  //RFID reader
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(SS_PIN, RST_PIN); // Init each MFRC522 card
  //  mfrc522.PCD_DumpVersionToSerial();

  //LCD
  lcd.initialize();
  lcd.updateString("RFID Reader Push Button and Touch me!! ", 0);
  lcd.updateString("Push Button and Touch me!! ", 1);

  //  //ssXBee
  //  ssXBee.begin(9600);
}

/**
   Main loop.
*/
void loop() {
  if (buttons.updateLastButtonNumber()) {
    String tempLCDStr = "";
    tempLCDStr += " Button: ";
    tempLCDStr += String(buttons.lastButtonNumber);
    lcd.updateString(tempLCDStr, 1);
  }

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) { // Look for new cards
    // Show some details of the PICC (that is: the tag/card)
    //    Serial.print(F("New Card Detected!! Card UID:"));
    String tempUidStr = dump_byte_array_to_string(mfrc522.uid.uidByte, mfrc522.uid.size);
    tempUidStr.trim();
    //    Serial.print(tempUidStr);
    //    Serial.println();

    //    Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    //    Serial.println(mfrc522.PICC_GetTypeName(piccType));

    mfrc522.PICC_HaltA(); // Halt PICC
    mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD

    //    //ssXBee
    //    String xbeeStr = "RFID-UID,";
    //    xbeeStr += tempUidStr;
    //    ssXBee.println(xbeeStr);

    //buttons
    //    Serial.print("lastButtonNumber: ");
    //    Serial.println(buttons.lastButtonNumber);

    //data send
    Serial.print(PACKET_PREFIX_RRN);
    Serial.print(",");
    Serial.print(tempUidStr);
    Serial.print(",");
    Serial.print(buttons.lastButtonNumber);
    Serial.println("");

    //LCD
    String tempLCDStr = "";
    tempLCDStr += " Button: ";
    tempLCDStr += String(buttons.lastButtonNumber);
    tempLCDStr += " RFID-UID: ";
    tempLCDStr += tempUidStr;
    lcd.updateString(tempLCDStr, 1);

    //speaker
    melody(SPEAKER_PIN);
  } //if (mfrc522.PICC_IsNewC

  //LCD
  lcd.scroll(300);
}

/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

String dump_byte_array_to_string(byte *buffer, byte bufferSize) {
  String str = "";
  for (byte i = 0; i < bufferSize; i++) {
    str += String(buffer[i] < 0x10 ? " 0" : " ");
    str += String(buffer[i], HEX);
  }
  return str;
}
