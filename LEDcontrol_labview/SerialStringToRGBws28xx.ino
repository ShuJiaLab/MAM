/*
  Serial WS2812 RGB controller

*/
#include <Z:\Dylan\MAM\Software\ArduinoProjects-master (1)\ArduinoProjects-master\SerialStringToRGBws28xx\Adafruit_NeoPixel.h>
//#include <Adafruit_NeoPixel.h>
#define PIN 7
#define LED_COUNT 12

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

String inString;    // string to hold input
int currentColor = 0;
int red, green, blue = 0;


void setup() {
  // Open serial communications and wait for port to open:
  leds.begin();
  //Serial.begin(9600);
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}



void loop() {
  int inChar;
  
  // Read serial input:
  if (Serial.available() > 0) {
    inChar = Serial.read();
  }

  if (isDigit(inChar)) {
    // convert the incoming byte to a char
    // and add it to the string:
    inString += (char)inChar;
  }

    if (inChar == ',') {
    switch (currentColor) {
      case 0:    // 0 ==> NOT WORKING : dylan, BUT REMEMBER RED
        red = inString.toInt();                       
        inString = "";                                  // clear the string for new input:
        leds.setPixelColor(0, leds.Color(0, 0, blue));  // ==> not working : dylan    
        for (int k =1; k<LED_COUNT; k++){
              leds.setPixelColor(k, leds.Color(0,0, blue));
        } leds.show();
                                           //Serial.println(String(red,BIN));
        break;      

      
       case 1:    //GREEN--> BLUE CHANNEL
        blue = inString.toInt();                      
        inString = "";                                // clear the string for new input:                                      
        leds.setPixelColor(0,leds.Color(red,0,blue)); 
        for (int j =1; j<LED_COUNT; j++){
                leds.setPixelColor(j,leds.Color(red,0,blue)); 
         } leds.show();

         if (blue==0){   // 2. RED --> BLACK
              // delay(1000); //////////////////// for red delay
         
       //  leds.setPixelColor(0, leds.Color(0, 0, 0));
        //  for (int pk = 1; pk<LED_COUNT; pk++){
        //       leds.setPixelColor(pk, leds.Color(0, 0, 0));}
               } 
       //leds.show(); 
                                               // Serial.println(String(blue,BIN));
         
         break;
    }
    currentColor++;  
  }



  
  // if you get a newline, you know you've got

  if (inChar == '\n') {    
   // green = inString.toInt();
    //Serial.println(currentColor);   20190718

  /* if (blue==0){   // 2. RED --> BLACK
              delay(3000); // for red delay
    
    leds.setPixelColor(0, leds.Color(0, 0, 0));
    for (int pk = 1; pk<LED_COUNT; pk++){
       leds.setPixelColor(pk, leds.Color(0, 0, 0));}
       } leds.show(); */
    
   if (blue!=0){   // 1. BLUE FIRST
     leds.setPixelColor(0, leds.Color(0, 0, blue));
    for (int pp = 1; pp<LED_COUNT; pp++){
    leds.setPixelColor(pp, leds.Color(0, 0, blue));}
    leds.show(); }
   

    // clear the string for new input:
  inString = "";
    // reset the color counter:
  currentColor = 0;
  }
    }
