#define PWM 11

void setup() {
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
}

void loop() {
  for (int i=100; i<=255; i++){
    Serial.print("Nilai PWN = ");
    Serial.println(i);
    analogWrite(PWM, i);
    delay(100);
  }
}
