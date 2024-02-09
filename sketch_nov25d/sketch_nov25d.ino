//#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#define dataPin 8

#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

//LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
dht DHT;
void setup() {
  Serial.begin(9600);
  //lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  lcd.init();
  lcd.backlight();
}
void loop() {
  int readData = DHT.read22(dataPin);
  int t = DHT.temperature;
  int h = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Temp- "); // Prints string "Temp." on the LCD
  lcd.print(t); // Prints the temperature value from the sensor
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi- ");
  lcd.print(h);
  lcd.print(" %");
  delay(2000);
}
