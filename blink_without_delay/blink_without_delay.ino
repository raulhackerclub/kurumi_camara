#define ledPin 13
#define interval 500

int pinState = LOW;  
unsigned long previousMillis = 0;  

void setup() 
{  
  pinMode(ledPin, OUTPUT);
}

void loop() 
{  
  int state = currentPinState();
  digitalWrite(ledPin, state);
}

int currentPinState()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;

    if (pinState == LOW) {
      pinState = HIGH;
    } else {
      pinState = LOW;
    }
  }
  return pinState;
}
