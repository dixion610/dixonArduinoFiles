#include<Servo.h>
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define smokePin A5
#define enablePinOne 6
#define enablePinTwo 5
#define servoPin 3
int delayValue = 2000;
int smokePinValue = 0;
Servo servo;
void setup() {
  servo.attach(servoPin);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(enablePinOne,OUTPUT);
  pinMode(enablePinTwo,OUTPUT);

}

void loop() {
  smokePinValue = analogRead(smokePin);
 while(smokePinValue < 160){
  moveForward();
  smokePinValue = analogRead(smokePin);
 }
 while(smokePinValue > 160){
  moveServo();
  smokePinValue = analogRead(smokePin);
 }
}

void turnLeft(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

int turnRight(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  return 10;
}

void moveForward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void moveReverse(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void moveMoters(boolean IN1State,boolean IN2State, boolean IN3State, boolean IN4State){
  digitalWrite(IN1,IN1State);
  digitalWrite(IN2,IN2State);
  digitalWrite(IN3,IN3State);
  digitalWrite(IN4,IN4State);
}

void moveServo(){
  for(int loopVariable = 0; loopVariable < 179; loopVariable++){
    servo.write(loopVariable);
  }
  for(int loopVariable =180; loopVariable >0; loopVariable--){
     servo.write(loopVariable);
  }
}
