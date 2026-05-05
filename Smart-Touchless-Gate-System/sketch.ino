#include <Servo.h>
Servo gate;
const int servo = 6;
const int trig = 9;
const int echo = 7;


void setup() {
  gate.attach(servo);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);


  Serial.begin(9600);
}

void loop() {
  // send Wave
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  // conver time to disatnce
  int distance = duration * 0.034 / 2;


  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20 && distance > 0) {
    gate.write(90);
    delay(3000);
  } else {
    gate.write(0);
  }
  delay(100);
}
