#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

const byte slaveId = 1;

const int hitButton = 2;
const int stayButton = 3;

volatile bool isWaiting = true;
char playerAction = 'a';

void setup()
{ 
  lcd.begin(16,2);
  lcd.setCursor(0,0);

  pinMode(hitButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hitButton),interruptHit , FALLING);

  pinMode(stayButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(stayButton), interruptStay, FALLING);
  
  Wire.begin(slaveId); 
  Wire.onRequest(requestEvent);
 
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);    
}

void loop()
{
}

void requestEvent()
{
  while(Wire.available() > 0)
  {
    while(isWaiting)
  {
    lcd.clear();
    lcd.print("Hit/Stay: ");
    
    delay(250);
  }

  Wire.write(playerAction);

  }
}

void interruptHit()
{
  isWaiting = false;
  playerAction = 'H';
}

// going from interrupted state bac to counting
void interruptStay()
{
  isWaiting = false;
  playerAction = 'S';
}
