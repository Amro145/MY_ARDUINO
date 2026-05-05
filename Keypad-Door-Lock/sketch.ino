#include <Keypad.h>    
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {6, 7, 8, 9};
byte colPins[COLS] = {2, 3, 4, 5};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo Setup

Servo myServo;
char masterCode[] = "1234";
char inputCode[5];
byte inputCount = 0;


void setup() {
  myServo.attach(10);
  myServo.write(0);
  Serial.begin(9600);

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter PIN:");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print(key);

    lcd.setCursor(inputCount, 1);
    lcd.print('*');

    inputCode[inputCount] = key;
    inputCount++;
    if (inputCount == 4) {
      inputCode[4] = '\0'; 

      lcd.clear();
      lcd.setCursor(0, 0);
      if (strcmp(inputCode, masterCode) == 0) {
        Serial.println("Access Granted!");
        lcd.print("Access Granted!");
        myServo.write(90);
        delay(3000);
        myServo.write(0);
      } else {
        Serial.println("Access Denied!");
        lcd.print("Access Denied!");
        delay(2000);
      }
      inputCount = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter PIN:");
    }
  }

}
