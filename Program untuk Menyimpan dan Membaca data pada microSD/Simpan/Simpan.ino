#include <SPI.h>
#include <SD.h>
#define SS 10
File myFile;

void setup(){
  Serial.begin(9600);
  Serial.println("Inisialisasi microSD...");
  if(!SD.begin(SS)){
    Serial.println("Inisialisasi gagal");
    while (1);
  } else {
    Serial.println("Inisialisasi sukses");
    Serial.println("Menyimpan file...");
    myFile = SD.open("log.txt", FILE_WRITE);
    if (myFile){
      myFile.println("Nama = Muhammad Gibran");
      myFile.println("Nama = Karawang");
      myFile.println("Hobby = Gambar");
      MyFile.close();
      Serial.println("penyimpanan selesai");
    } else {
      Serial.println("Gagal membuka File");
    }  
  }
}

void loop(){}
