#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
 
void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  lcd.print("ask the");
  lcd.setCursor(0, 1);
  lcd.print("crystal Ball");
}

void loop() {
  switchState = digitalRead(switchPin);

  Serial.print("switch state = ");
  Serial.println(switchState);
  
  if(switchState != prevSwitchState) {
    if(switchState == LOW){
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);

      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("No");
        break;
        case 2:
        lcd.print("Go fuck yourself");
        break;
        case 3:
        lcd.print("Bush did 9/11");
        break;
        case 4:
        lcd.print("Hayden's cake");
        break;
        case 5:
        lcd.print("Ask your mom");
        break;
        case 6:
        lcd.print("Ligma crystal ballz");
        break;
        case 7:
        lcd.print("Does a bear shit in the woods?");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
