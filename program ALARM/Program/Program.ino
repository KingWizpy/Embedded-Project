#include <LiquidCrystal.h>
#include <RTClib.h>
#include <Wire.h>

const int rs = 2, e = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
RTC_DS1307 rtc;
int detik = 30;
int menit = 6;
int jam = 22;
int hari = 7;
int bulan = 4;
int tahun = 2022;

vold setup() {
  lcd.begin(16,4);
  Serial.begin(9600);
  if(!rtc.begin()){  
    Serial.println("DS1307 tidak terdeteksi");
    while(1);
  } if(!rtc.isrunning()){
    Serial.println("RTC Tidak Aktif!");
    rtc.adjust(DateTime(2022,2,2,0,0,0));
  } else {
    Serial.println("Program alarm!");
  }
}  

void loop (){ 
  // Waktu pada Virtual terminal
  DateTime now = rtc.now();
  Serial.print(now.day(),DEC);
  Serial.print('/');
  Serial.print(now.month(),DEC);
  Serial.print('/');
  Serial.print(now.year(),DEC);
  Serial.print(' ');
  Serial.print(now.hour(),DEC);
  Serial.print(':');
  Serial.print(now.minute(),DEC);
  Serial.print(':');
  Serial.print(now.second(),DEC);
  Serial.println();

  //Waktu pada LCD
  lcd.print(now.day(),DEC);
  lcd.print('/');
  lcd.print(now.month(),DEC);
  lcd.print('/');
  lcd.print(now.year(),DEC);
  lcd.print('|');
  lcd.print(now.hour(),DEC);
  lcd.print(':');
  lcd.print(now.minute(),DEC);
  lcd.print(':');
  lcd.print(now.second(),DEC);
  lcd.println();
  delay(1000);
  lcd.clear();

  //Alarm
  if (now.year()==tahun & now.month()=bulan & now.day()==hari & now.hour()==jam & now.miniute()==menit & now.second()==detik){
    lcd.clear();
    lcd.println("Alarm Menyala");
    delay(10000);
    exit(0);
    lcd.clear();  
  }
}
