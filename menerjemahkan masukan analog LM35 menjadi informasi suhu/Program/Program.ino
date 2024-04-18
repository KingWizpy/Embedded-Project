#include <LiquidCrystal.h>
const int rs = 2, e = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
int temp;
int sensorpin = A0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,4);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(sensorpin);
  temp = temp*0.4883;
  lcd.setCursor(3,1);
  lcd.print("Suhu : ");
  lcd.print(temp);
  lcd.print("C");
  delay(500);
  lcd.clear();
}
