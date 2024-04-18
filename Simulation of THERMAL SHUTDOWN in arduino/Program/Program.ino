#include <LiquidCrystal.h>
#define PWM 11

String data_masuk = "";
const int rs = 2, e = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
int temp;
int sensorpin = A0;

//Maksimal suhu
int makssuhu = 80;

void setup(){
  lcd.begin(16,4);
  pinMode(PWM, OUTPUT);
  Serial.begin(9600);
  Serial.println("Apa yang ingin kamu lakukan?");
  Serial.println("1.Nyalakan lampu 2.Keluar");
}

void loop(){
  if(Serial.available() > 0) {
    char ascii = Serial.read();
    if (ascii != '/r')
      data_masuk = data_masuk + ascii;
    else {
      if (data_masuk == "1"){
        for (int i=0; i<=255; i++){
          if(i==0){
            Serial.println("Menyalakan Device...");
          }

          //Suhu
          lcd.setCursor(1,0);
          temp = analogRead(sensorpin)+(i/10);
          temp = temp*0.4883;
          lcd.println("Suhu : ");
          lcd.print(temp);
          lcd.println("C");
          Serial.print("Suhu : ");
          Serial.println(temp);

          //Pwm
          lcd.println("");
          lcd.print("Nilai PWM : ");
          lcd.println(i);
          Serial.print("Nilai PWM : ");
          Serial.println(i);
          analogWrite(PWM, i);

          //Overheat
          if(temp >= makssuhu){
            lcd.clear();
            delay(800);
            lcd.setCursor(1,0);
            lcd.println("Device overheat");
            lcd.println("Suhu : ");
            lcd.print(temp);
            lcd.print("C");
            analogWrite(PWM,0);
            delay(5000);
            exit(0);
          }
          delay(50);
          lcd.clear();
          if(i >= 255){
            setup();
          }
        }
      } else if (data_masuk == "2"){
        analogWrite(PWM,0);
        Serial.println("keluar...");
        delay(3000);
        exit(0);
      } else {
        Serial.println("Kamu menulis selain pilihan diatas yaitu " + data_masuk);
      }
      data_masuk = "";
    }
  }
}
