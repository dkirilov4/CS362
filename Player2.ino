#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

const byte slaveId = 2;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  
  Wire.begin(slaveId); 
  Wire.onReceive(receiveEvent);
 
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);    
}

void loop()
{
}

void receiveEvent(int howMany)
{
  char inChar;
  
  while(Wire.available() > 0)
  {
    inChar = Wire.read();  

    lcd.print(inChar);
  }
}
