#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <Wire.h>
#include <SparkFunBME280.h>

#define dataPin 8

BME280 mySensor;
LiquidCrystal_I2C lcd(0x27,16,2);
dht DHT;

byte degree_symbol[] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};
byte DHT_symbol[] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01001,
  B01001,
  B01001,
  B01110
};
byte BME_symbol[] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01001,
  B01110,
  B01001,
  B01110
};
byte equal_symbol[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};

void setup()
{
  Serial.begin(9600);
  mySensor.setI2CAddress(0x76);
  mySensor.beginI2C();
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, degree_symbol);
  lcd.createChar(1, DHT_symbol);
  lcd.createChar(2, BME_symbol);
  lcd.createChar(3, equal_symbol);
  lcd.home();
}

void loop(){ 
  int readData = DHT.read22(dataPin);
  
  int temp1 = DHT.temperature;
  int hum1= DHT.humidity;
  int temp2 = mySensor.readTempC();
  int hum2 = mySensor.readFloatHumidity();
  
  Serial.print(" Temp1: ");
  Serial.print(temp1);
  Serial.print(" *C ");
  Serial.print("   Humi1: ");
  Serial.print(hum1);
  Serial.println(" % ");
  Serial.print(" Temp2: ");
  Serial.print(temp2);
  Serial.print(" *C ");
  Serial.print("   Humi2: ");
  Serial.print(hum2);
  Serial.println(" % ");
  
  lcd.setCursor(0,0);
  lcd.print("T");
  lcd.write(1);
  lcd.write(3);
  lcd.print(temp1);
  lcd.write(0);
  lcd.print("C, H");
  lcd.write(1);
  lcd.write(3);
  lcd.print(hum1);
  lcd.print(" %");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("T");
  lcd.write(2);
  lcd.write(3);
  lcd.print(temp2);
  lcd.write(0);
  lcd.print("C, H");
  lcd.write(2);
  lcd.write(3);
  lcd.print(hum2);
  lcd.print(" %");
  delay(500);
}

 
