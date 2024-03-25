#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 2
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

void setup() 
{ 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); 
}

void loop() 
{ 
  for(int i=0;i<16;i++)
  {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(500);
    
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(500);
  }
}
