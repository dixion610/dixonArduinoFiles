#define servoPin 8
#define flexPin A5
#include<Servo.h>
Servo servo;
int flexValue;
int flexAngle;
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(flexPin,INPUT);
}

void loop() {
  flexValue = analogRead(flexPin);
  //Serial.println(flexValue);
  flexAngle = map(flexValue,40,290,0,179);
  servo.write(flexAngle);
  delay(100);
}
