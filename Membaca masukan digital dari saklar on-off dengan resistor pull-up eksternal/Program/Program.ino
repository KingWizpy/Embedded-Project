#define swl digitalRead(13)  
#define sw2 digitalRead(11)  
#define sw3 digitalRead(9) 
 
void setup() {  
    Serial.begin (9600);  
    pinMode (13, INPUT_PULLUP);  
    pinMode (11, INPUT_PULLUP);  
    pinMode (9, INPUT_PULLUP) ;  
}  
void loop() (  
    // Ditekan \& Dilepas  
    if (sw1 == 0) Serial.println("Tombol 1 ditekan");  
    if (sw1 == 1) Serial.println("Tombol-1 dilepas");  
    if (sw2 == 0) Serial.println("Tombol 2 ditekan");  
    if (sw2 == 1) Serial.println("Tombol-2 dilepas");  
    if (sw3 == 0) Serial.println("Tombol 3 ditekan");  
    if (sw3 == 1) Serial.println("Tombol-3 dilepas");  
    Serial.println("");  
    delay (5000);  
}
