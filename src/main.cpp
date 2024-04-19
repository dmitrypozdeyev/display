#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define VDD 2
#define V0 3
#define RS 4
#define RW 5
#define EN 6
#define D4 11
#define D5 12
#define D6 9
#define D7 10

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


int contrast = 0;
String str1;
String str2;
String str3;
String str4;

String incoming_data;


void setup() {
  pinMode(VDD, OUTPUT);
  digitalWrite(VDD, HIGH);
  pinMode(V0, OUTPUT);
  pinMode(RW, OUTPUT);
  digitalWrite(RW, LOW);
  lcd.begin(20, 4);
  Serial.begin(9600);
  analogWrite(V0, 70);  
  }

void loop() {
  incoming_data = Serial.readString();
  if (incoming_data.substring(0,1) == "t"){
    lcd.setCursor(0, 0);
    lcd.print(incoming_data.substring(1, 21));
    lcd.setCursor(0, 1);
    lcd.print(incoming_data.substring(21, 41));
    lcd.setCursor(0, 2);
    lcd.print(incoming_data.substring(41, 61));
    lcd.setCursor(0, 3);
    lcd.print(incoming_data.substring(61, 81));
    Serial.println("ok");
  }
  if (incoming_data.substring(0,1) == "e") Serial.println("ok");
  
  if (incoming_data.substring(0,1) == "c"){
    String contrast = incoming_data.substring(1, 3);  
    analogWrite(V0, contrast.toInt());
    Serial.println("ok"); 
  }
}