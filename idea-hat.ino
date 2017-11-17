#include <Encoder.h>
#include <Adafruit_NeoPixel.h>
 





#define tach1 2
#define tach2 3 
#define forwardPin 8
#define backwardPin 9
#define pwmPin 6

#define PIN      10
#define N_LEDS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
Encoder myEnc(tach1, tach2);


int motorSpeed = 180;

void setup() {
motorAttach();
strip.begin();
}



void loop() {

  int sensor = analogRead(A0);
  if (sensor > 300) {
   motorWrite(150);
   chase(strip.Color(255, 0, 0));
   chase(strip.Color(0, 255, 0)); 
   chase(strip.Color(0, 0, 255)); 
 } 
  else {
    motorWrite(0);
  }
 
  

}



