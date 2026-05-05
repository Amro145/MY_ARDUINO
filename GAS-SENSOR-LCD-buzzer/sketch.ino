#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


const int gasPin = A0;
const int buzzerPin = 8;
const int ledPin = 13;
const int GledPin = 12;

int thereGas = 480;
void setup() {
  pinMode(gasPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);


  // LCD

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();

}

void loop() {
  int sensorValue = analogRead(gasPin);
  Serial.print("Gas Level: ");
  Serial.println(sensorValue);
  int gasPercent = map(sensorValue, 0, 1023, 0, 100);
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasPercent);
  lcd.print("%   ");


  if (sensorValue > thereGas) {
    lcd.setCursor(0, 1);
    lcd.print(" GAS LEAK!   ");
    for (int i = 500; i <= 2000; i = i + 20) {
      tone(buzzerPin, i);
      delay(5);
    }

    digitalWrite(ledPin, HIGH);
    digitalWrite(GledPin, LOW);

  } else {
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    digitalWrite(GledPin, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Air Quality: OK ");


  }
  delay(100);
}
