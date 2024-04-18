String data_masuk = "";  
void setup() {  
// put your setup code here, to run once:  
    Serial.begin (9600);  
    Serial.println("Apa yang ingin kamu tanyakan?");  
    Serial.println("1.Nama 2.Kelas 3.NPM");  
}  
void loop () {  
    if (Serial.available {} > 0 ) \{  
        char ascii = Serial.read();  
        if (ascii != '\r' )  
            data_masuk = data_masuk + ascii;  
        else {  
            if (data_masuk == "1" ) {  
                Serial.println("Nama : Muhammad Gibran");  
            } else if (data_masuk == "2") {  
                Serial.println("Kelas : 4D");  
            } else if (data_masuk == "3") {  
                Serial.println("NPM : 2010631170097");  
            } else {  
                Serial.println("Kamu menulis selain pilihan diatas yaitu " + data_masuk);  
            }  
                data_masuk = "";  
         }
       }  
    }  
