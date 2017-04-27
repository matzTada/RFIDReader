/*
  Melody

  Plays a melody

  circuit:
   8-ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone

  2017/4/21 Modified by TadaMatz

*/
#include "speaker.h"

#define SPEAKER_PIN 5

void setup() {
  melody(SPEAKER_PIN);
}

void loop() {
  // no need to repeat the melody.
}
