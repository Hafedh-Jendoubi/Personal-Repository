const int ledG = 10;
const int ledR = 11;
const int Capt1 = 12;
const int Capt2 = 13;

#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  pinMode(Capt1, INPUT);
  pinMode(Capt2, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Parking Esprit\n");
}

void loop() {
  if(digitalRead(Capt1) == HIGH){
    lcd.clear();
    lcd.setCursor(4, 0); lcd.print("Bienvenu");
    clignoter(ledG);
  }
  else if(digitalRead(Capt2) == HIGH){
    lcd.clear();
    lcd.setCursor(4, 0); lcd.print("Au revoir");
    clignoter(ledR);
  }else{
    lcd.clear();
    lcd.setCursor(1, 0); lcd.print("Parking Esprit");
    delay(250); //This delay() is used to avoid screen problem!
  }
}

void clignoter(int led)
{
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}
