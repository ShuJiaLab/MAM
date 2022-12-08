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
#define brightness 250 // brightness of all LEDs, ranging from 0 to 255

// send how many pixels, and which pin to use to send signals to the library
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(brightness);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.fill(blue, 0, NUMPIXELS); //set all pixels to the same color defined
  pixels.setBrightness(brightness);
  pixels.show();
  //while(1)
}
