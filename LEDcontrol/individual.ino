// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS     12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30000; //3[sec] * 1000 delay for half a second // waiting for exposure time
int felayval = 10*60; //5[min] * 60 delay for next time

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  
    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(250,0,0)); // Moderately bright green color.
  
    pixels.setPixelColor(7, pixels.Color(100,0,0));
   pixels.setPixelColor(3, pixels.Color(30,0,0));
    pixels.setPixelColor(1, pixels.Color(30,0,0));
    pixels.setPixelColor(2, pixels.Color(100,0,0));
       pixels.setPixelColor(5, pixels.Color(50,0,0));
        pixels.setPixelColor(4, pixels.Color(100,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
  

/*
  while (1) {
     pixels.setPixelColor(11, pixels.Color(250,0,0)); // Moderately bright green color.
     pixels.setPixelColor(10, pixels.Color(250,0,0)); // Moderately bright green color.
    pixels.setPixelColor(7, pixels.Color(50,0,0)); // Moderately bright green color.
    pixels.setPixelColor(6, pixels.Color(250,0,0)); // Moderately bright green color.
    pixels.setPixelColor(3, pixels.Color(250, 0, 0)); // Moderately bright green color.
    pixels.setPixelColor(2, pixels.Color(50, 0, 0)); // Moderately bright green color.
     pixels.setPixelColor(9, pixels.Color(250,0,0)); // Moderately bright green color.
    pixels.setPixelColor(8, pixels.Color(50,0,0)); // Moderately bright green color.
    pixels.setPixelColor(5, pixels.Color(250,0,0)); // Moderately bright green color.
    pixels.setPixelColor(4, pixels.Color(250,0,0)); // Moderately bright green color.
    pixels.setPixelColor(1, pixels.Color(250, 0, 0)); // Moderately bright green color.
    pixels.setPixelColor(0, pixels.Color(250, 0, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval);

    for (int ld = 0; ld < NUMPIXELS; ld++) {
      pixels.setPixelColor(ld, pixels.Color(0, 0, 0));
      pixels.show();
    }
    for (int p=0; p<felayval;p++) {
     delay(1000);
        
    }
  }

*/




}
