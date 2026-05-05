#define DECODE_NEC
#include <IRremote.h>

const int irPin = 2;
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
const int numLeds = 9;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing System...");

  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  IrReceiver.begin(irPin, DISABLE_LED_FEEDBACK);
  Serial.println("System Ready! Press buttons 1 to 9...");
}

void activateOnlyOneLed(int targetPin) {
  for (int i = 0; i < numLeds; i++) {
    if (ledPins[i] == targetPin) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long command = IrReceiver.decodedIRData.command;
    IrReceiver.resume();

    Serial.print("Signal Detected! Command: ");
    Serial.println(command);

    switch (command) {
      case 48:
        activateOnlyOneLed(3);
        Serial.println("LED 1 is ON");
        break;
      case 24:
        activateOnlyOneLed(4);
        Serial.println("LED 2 is ON");
        break;
      case 122:
        activateOnlyOneLed(5);
        Serial.println("LED 3 is ON");
        break;
      case 16:
        activateOnlyOneLed(6);
        Serial.println("LED 4 is ON");
        break;
      case 56:
        activateOnlyOneLed(7);
        Serial.println("LED 5 is ON");
        break;
      case 90:
        activateOnlyOneLed(8);
        Serial.println("LED 6 is ON");
        break;
      case 66:
        activateOnlyOneLed(9);
        Serial.println("LED 7 is ON");
        break;
      case 74:
        activateOnlyOneLed(10);
        Serial.println("LED 8 is ON");
        break;
      case 82:
        activateOnlyOneLed(11);
        Serial.println("LED 9 is ON");
        break;
      case 162:
        activateOnlyOneLed(0);
        Serial.println("ALL LEDs OFF");
        break;
    }
  }
}