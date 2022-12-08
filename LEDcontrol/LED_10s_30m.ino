//this code sets all LED the same color using the fill() function

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

//board parameters
#define PIN        7 // pin on the Arduino is connected to the NeoPixels
#define NUMPIXELS 12 // number of NeoPixels attached to the Arduino

//colors
#define red pixels.Color(255, 0, 0) // color red as of uint32
#define green pixels.Color(0, 255, 0) // color green as of uint32
#define blue pixels.Color(0, 0, 255) // color blue as of uint32

//birghtness
#define brightness 254 // brightness of all LEDs, ranging from 0 to 255

//time control
#define DELAY 20 //in s
#define INTERVAL 1780//in s
#define SETUP 0//time left for setup, in min
#define CYCLES 24

// send how many pixels, and which pin to use to send signals to the library
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(brightness);
}

void loop() {
  pixels.clear();// Set all pixel colors to 'off'
  //pixels.fill(blue, 0, NUMPIXELS); //set all pixels to the same color defined
  //pixels.setBrightness(brightness);
  //pixels.show();
  for(int i = 0; i<CYCLES; i++) {
    pixels.fill(blue, 0, NUMPIXELS);
    pixels.setBrightness(brightness);
    pixels.show();
    for(int j = 0;j < DELAY; j++) {
      delay(1000);   
    }
    pixels.clear();
    //delay(DELAYVAL);;//keep the light on for capturing
    pixels.fill(blue, 0, NUMPIXELS);
    pixels.clear();
    pixels.show();
    for(int k = 0;k < INTERVAL; k++) {
      delay(1000);   
    }
    pixels.clear();
  }
  pixels.setBrightness(255);
  pixels.show();
  delay(5000);
  //exit(0);
  while(1);
}
