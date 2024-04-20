#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 2
#define CLOCK_PIN 13
#define interval 500

CRGB leds[NUM_LEDS];

CRGB::HTMLColorCode pinState = CRGB::Black;  
unsigned long previousMillis = 0;  

void setup() 
{  
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); 
}

void loop() 
{  
  CRGB::HTMLColorCode state = currentPinState();
  leds[0] = state;
  FastLED.show();
}

int currentPinState()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;

    if (pinState == CRGB::Black) {
      pinState = CRGB::BlueViolet;
    } else {
      pinState = CRGB::Black;
    }
  }
  return pinState;
}