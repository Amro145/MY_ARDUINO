const int buzzer = 5;


void setup() {

pinMode(buzzer, OUTPUT);
}

void loop() {
digitalWrite(buzzer, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
delay(300);

}
