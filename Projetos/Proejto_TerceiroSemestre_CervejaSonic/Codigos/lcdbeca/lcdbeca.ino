#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{ 
  Wire.begin(13, 25); // ESSENCIAL pro ESP32
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop()
{
  lcd.setCursor(2, 0);
  lcd.print("SONIC BOOM BAR!!!!");
  delay(1000);
  lcd.clear();
}