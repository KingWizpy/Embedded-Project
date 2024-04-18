#include <Arduino_FreeRTOS.h>

void Task_Controlled(void *param);
void Task_Print(void *param);
int inputpotensio = A0;
int nilaipotensio = 0;

void setup(){
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, INPUT_PULLUP);

  xTaskCreate(Task_potensio, "T1", 100, NULL,1,NULL);
  xTaskCreate(Task_LEDRED, "T2", 100, NULL,2,NULL);
  xTaskCreate(Task_LEDBLUE, "T3", 100, NULL,3,NULL);
  xTaskCreate(Task_LEDWHITE, "T4", 100, NULL,4,NULL);
}

void loop(){
  nilaipotensio = analogRead(inputpotensio);
}

void Task_LEDRED(void *param){
  (void) param;
  while(1){
    if(digitalRead(8) == 0){
      while(digitalRead(8) == 0);
      digitalWrite(11,LOW);
      vTaskDelay(1000/portTICK_PERIOD_MS);
    } else digitalWrite(11,HIGH)'
  }
}

void Task_LEDBLUE(void *param){
  (void) param;
  while(1){
    if(digitalRead(8) == 0){
      while(digitalRead(8) == 0);
      digitalWrite(12,LOW);
      vTaskDelay(2000/portTICK_PERIOD_MS);
    } else digitalWrite(12,HIGH)'
  }
}

void Task_LEDWHITE(void *param){
  (void) param;
  while(1){
    if(digitalRead(8) == 0){
      while(digitalRead(8) == 0);
      digitalWrite(13,LOW);
      vTaskDelay(3000/portTICK_PERIOD_MS);
    } else digitalWrite(13,HIGH)'
  }
}

void Task_Potensio(void *param){
  (void) param;
  while(1){
    Serial.print("Nilai Potensio : ");
    Serial.println(nilaipotensio);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
