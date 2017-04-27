/**
   --------------------------------------------------------------------------------------------------------------------
   Example sketch/program showing how to read data from more than one PICC to serial.
   --------------------------------------------------------------------------------------------------------------------
   This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid

   Example sketch/program showing how to read data from more than one PICC (that is: a RFID Tag or Card) using a
   MFRC522 based RFID Reader on the Arduino SPI interface.

   Warning: This may not work! Multiple devices at one SPI are difficult and cause many trouble!! Engineering skill
            and knowledge are required!

   @license Released into the public domain.

   Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS 1    SDA(SS)      ** custom, take a unused pin, only HIGH/LOW required *
   SPI SS 2    SDA(SS)      ** custom, take a unused pin, only HIGH/LOW required *
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15

*/

/*
   2017/4/15 Modified by TadaMatz
   Tell card id beased on UID
   RGB LED is optional

   2017/4/21 Modified by TadaMatz
   Delete RGB
   Add Piezzo Speaker
*/

//RFID reader
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN        10         // Configurable, take a unused pin, only HIGH/LOW required, must be diffrent to SS 2
MFRC522 mfrc522;   // Create MFRC522 instance.

//speaker
#include "speaker.h"
#define SPEAKER_PIN 8

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
  mfrc522.PCD_DumpVersionToSerial();

  //  //ssXBee
  //  ssXBee.begin(9600);
}

/**
   Main loop.
*/
void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) { // Look for new cards
    // Show some details of the PICC (that is: the tag/card)
    Serial.print(F("New Card Detected!! Card UID:"));
    String tempUidStr = dump_byte_array_to_string(mfrc522.uid.uidByte, mfrc522.uid.size);
    tempUidStr.trim();
    Serial.print(tempUidStr);
    Serial.println();

    Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));

    mfrc522.PICC_HaltA(); // Halt PICC
    mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD

    //    //ssXBee
    //    String xbeeStr = "RFID-UID,";
    //    xbeeStr += tempUidStr;
    //    ssXBee.println(xbeeStr);

    //speaker
    melody(SPEAKER_PIN);
  } //if (mfrc522.PICC_IsNewC
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
