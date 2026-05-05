#include <Servo.h>
Servo ServoX;
Servo ServoY;
const int pinX = A1;
const int pinY = A0;

void setup() {
ServoX.attach(10);
ServoY.attach(9);
Serial.begin(9600);
}

void loop() {
int valX = analogRead(pinX);
int valY = analogRead(pinY);

int angleX = map(valX, 0, 1023, 0, 180);
int angleY = map(valY, 0, 1023, 0, 180);

ServoX.write(angleX);
ServoY.write(angleY);


Serial.print("X: "); Serial.print(angleX);
Serial.print(" | Y: "); Serial.println(angleY);

delay(200);



}
