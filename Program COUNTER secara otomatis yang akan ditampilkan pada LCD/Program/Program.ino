#include <LiquidCrystal.h>
#define LED 6  
LiquidCrystal lod (12, 11, 5, 4, 3, 2);  

vold setup() {  
    1cd. clear ();  
    1cd.begin (16,2);  
    pinMode (LED, OUTPUT);  
}  

void loop (){ 
    for (int cacah = 0; cacah <= 50 ;cacah++ ) {  
        lcd.setCursor (01, 00);  
        lcd.print ("Bilangan Cacah");  
        1cd.setCursor(03,01);  
        lcd.print ("0-50 : ");  
        lcd.print (cacah) ;  
        delay (1000);  
        1cd.clear [] ;  
        digitalWrite (LED, !digitalRead (LED) ) ;  
    }  
    delay (1000);  
}
