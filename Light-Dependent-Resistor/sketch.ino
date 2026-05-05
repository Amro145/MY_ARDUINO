const int led  = 13;
const int ldr = A0;


void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(ldr);
  Serial.print("Current Reading: ");
  Serial.println(lightLevel);

  if (lightLevel > 500) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(200);

}
