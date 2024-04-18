#include <SPI.h>
#include <SD.h>
File myFile;

void setup(){
  Serial.begin(9600);
  Serial.println("Inisialisasi microSD...");
  if(!SD.begin(SS)){
    Serial.println("Inisialisasi gagal");
    while (1);
  } else {
    Serial.println("Inisialisasi sukses");
    Serial.println("Membaca isi file...");
    myFile = SD.open("log.txt");
    if (myFile){
      Serial.println("Isi File :");
      while (myFile.available()){
        Serial.write(myFile.read());
      } myFile.close();
    } else {
      Serial.println("Gagal membuka File");
    }  
  }
}

void loop(){}
