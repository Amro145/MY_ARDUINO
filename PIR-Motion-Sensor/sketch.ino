const int pir = 2;
const int led = 13;
const int buzzer = 10;

int pirState = LOW;
int value = 0;
void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  value = digitalRead(pir);
  if (value == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
    if (pirState == LOW) {
      Serial.println("⚠️ Motion detected!");
      pirState = HIGH;
    }
  }
  else {
    digitalWrite(led, LOW);
    noTone(buzzer);
    if (pirState == HIGH) {
      Serial.println("✅ Motion ended.");
      pirState = LOW;
    }
  }
}

