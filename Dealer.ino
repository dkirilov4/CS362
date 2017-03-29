#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup()
{
  Wire.begin();
 
  lcd.begin(16,2);
  lcd.setCursor(0,0);

  
}

void loop()
{
  //lcd.print("Dealer");
  
  Wire.beginTransmission(1);
  Wire.requestFrom(1, 1);
  while(Wire.available())
  {
    char c = Wire.read();
    lcd.print(c);
  }
  Wire.endTransmission();
 
  delay(500);
//  
  Wire.beginTransmission(1);
  Wire.write('L');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(2);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(2);
  Wire.write('L');
  Wire.endTransmission();
 
  delay(500);
}
