#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 2
#define CLOCK_PIN 13
#define interval 500
#define executionTime 3000

CRGB leds[NUM_LEDS];
int ledsCurrentState[NUM_LEDS];

CRGB::HTMLColorCode pinState = CRGB::Black;  
unsigned long previousMillis = 0;  

void setup() 
{  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  lightsOff();
}

void loop() 
{    
  // para cada leds
  //   veja o estado atual dele
  //   se o estado for 0
  //     defina o rgb para black
  //   se o estado for 2
  //     defina o rgb para green
  //   se o estado for 1
  //     defina o rgb baseado do currentPinState

  CRGB::HTMLColorCode state = currentPinState();
  leds[0] = state;

  FastLED.show();
}

int currentPinState()
{
  if (already500Gone())
  {
    pinState = toggledState(pinState);
  }
  return pinState;
}

 bool already500Gone()
 {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    return true;
  }
  else
  {
    return false;
  }
 }

CRGB::HTMLColorCode toggledState(CRGB::HTMLColorCode state)
 {
  if (pinState == CRGB::Black) 
  {
    pinState = CRGB::Green; // pinState = 0x007F00 [VERMELHO]
  } else {
    pinState = CRGB::Black;
  }

  return pinState;
}

void lightsOff() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    ledsCurrentState[i] =
  }
  FastLED.show();
}
