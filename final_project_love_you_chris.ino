#include "pitches.h"
#include <Adafruit_NeoPixel.h>

unsigned long startTime;
unsigned long endTime;
int interval;
int i;


Adafruit_NeoPixel strip(60, 6);
uint32_t color1 = strip.Color(239, 160, 11); //pink

int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

int durations[] = {
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8
};
int songLength = sizeof(melody)/sizeof(melody[0]);

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  int amtOfTime = millis();
  startTime = millis();
interval = 500;
}

void loop() {
    endTime = millis();
  if (endTime - startTime >= interval) {

  for (int thisNote = 0; thisNote < songLength; thisNote++){
    int duration = 1000/ durations[thisNote];
    tone(8, melody[thisNote], duration);
    int pause = duration * 1.3;
    delay(pause);
    // stop the tone
    noTone(8);
  }
  }
for (int i = 0; i <strip.numPixels(); i++){
strip.setPixelColor(i,color1);
strip.show();
}}
