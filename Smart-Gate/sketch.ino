#include <Servo.h>
Servo gate;
const int btn = 2;
const int led = 13;
const int servo = 9;

void setup() {

  gate.attach(servo);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);

  gate.write(90);
}

void loop() {
  const int status = digitalRead(btn);
  if (status == HIGH) {
    digitalWrite(led, HIGH);
    gate.write(0);
    delay(3000);
  } else {
    digitalWrite(led, LOW);
    gate.write(90);
  }

}
