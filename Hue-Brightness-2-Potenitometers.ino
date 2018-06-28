#include <Adafruit_NeoPixel.h>

//This sketch uses 1 pot to control the brightness and 1 pot to control the hue of a Neopixel strip

// constants won't change. They're used here to 
// set pin numbers:
const int ledPin = 2;     // the number of the neopixel strip
 int numLeds = 8;

//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, ledPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);

int potpin = 0;  // analog pin used to connect the potentiometer
int Potval;    // variable to read the value from the analog pin

int potpinBright = 1;  // analog pin used to connect the potentiometer
int PotvalBright;    // variable to read the value from the analog pin


void setup() {
  strip.begin();
  strip.setBrightness(40); // 1/3 brightness
  Serial.begin(9600);
}

void loop() {
  Potval = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Potval = map(Potval, 0, 1023, 0, 255);     // scale it to use it with rgb (value between 0 and 255)

  //brightness
    PotvalBright = analogRead(potpinBright);            // reads the value of the potentiometer (value between 0 and 1023)
  PotvalBright = map(PotvalBright, 0, 1023, 0, 255);     // scale it to use it with rgb (value between 0 and 255)

  //numLeds = Potval;
    
    rainbow(0);
    
  delay(10);


}


void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    //Serial.println(Potval);
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i*1+PotvalBright) & 255));
      strip.setBrightness(Potval); 
     
    }
    
    strip.show();
    delay(wait);
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {

  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}



