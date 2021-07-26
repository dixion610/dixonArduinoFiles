#include<Servo.h>
Servo servo;
int potValue = 0;
int mapValue = 0;
void setup() {
  servo.attach(6);
}

void loop() {
  potValue = analogRead(A5);
  Serial.println(potValue);
 /* for(int i=0;i<180;i++){
    servo.write(i);
  }
 for(int i=179;i>0;i++){
    servo.write(i);
  }*/

  mapValue = map(potValue,0,1023,0,179);
  servo.write(mapValue);
}
