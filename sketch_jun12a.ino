// This sketch uses 3 potentimeters to adjust the R, G and B values of a neopixel strip

#include <Adafruit_NeoPixel.h>

#define PIN 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);


int sensorValue = A0;
int sensorValue2 = A1;
int sensorValue3 = A2;
int currentColourValue;
int currentColourValue2;
int currentColourValue3;


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(40);
  
  
}

void loop() {
  
  
    
  
 currentColourValue = (255 - map( analogRead(sensorValue), 0, 1024, 0, 255 ) );
 currentColourValue2 = (255 - map( analogRead(sensorValue2), 0, 1024, 0, 255 ) );
 currentColourValue3 = (255 - map( analogRead(sensorValue3), 0, 1024, 0, 255 ) );
 
 colorWipe(strip.Color(currentColourValue, currentColourValue2, currentColourValue3), 50); // Red
 

 }

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(10);
  }
}
