#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

const int greenLed = 7;
const int redLed = 6;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  Serial.println("System Ready - Scan Card...");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    return;
  }

  Serial.print("Card UID:");
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println(content);

  if (content.substring(1) == "11 22 33 44") { 
    Serial.println("Access Authorized!");
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(greenLed, LOW);
  } else {
    Serial.println("Access Denied!");
    digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
  }
  
  mfrc522.PICC_HaltA();
}