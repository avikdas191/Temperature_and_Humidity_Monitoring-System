#include <LiquidCrystal_I2C.h>

#include <dht.h>

#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  lcd.setCursor(1,1); 
  lcd.print("Hello World !");

}
