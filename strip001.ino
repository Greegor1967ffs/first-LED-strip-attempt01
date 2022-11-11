#include <FastLED.h>

#define NUM_LEDS 4
#define DATAOUT 22

CRGB leds[NUM_LEDS];

int counter = 0;

void setup() {

  Serial.begin(9600);

  pinMode(DATAOUT, OUTPUT);
  
  delay(2000);
  FastLED.addLeds<WS2811, DATAOUT, RGB>(leds, NUM_LEDS);  
}

void loop() {
  for(int myLed = 0; myLed < NUM_LEDS; myLed = myLed + 1) {
      leds[myLed] = CRGB::Blue;
      FastLED.show();
      delay(100);
      leds[myLed] = CRGB::Black;
  }

  Serial.println(counter); 
  counter ++;
}
