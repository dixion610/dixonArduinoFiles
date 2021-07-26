#include<Servo.h>
Servo servo;
int potValue = 0;
int mapValue = 0;
int ldrValue = 0;

void setup() {
  servo.attach(13);
  pinMode(A5,INPUT);
}

void loop() {
  ldrValue = analogRead(A5);
  Serial.println(ldrValue);
  mapValue = map(ldrValue,0,100,0,179);
  servo.write(mapValue);
  delay(20);
}
