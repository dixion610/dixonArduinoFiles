#include<SoftwareSerial.h>
#define rx 2
#define tx 3
#define IN1 8
#define IN2 9
#define IN3 6
#define IN4 7
char bluetoothData;
SoftwareSerial softwareSerial(rx,tx);
void setup() {
  Serial.begin(9600);
  softwareSerial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  if(softwareSerial.available() > 0){
    bluetoothData = softwareSerial.read();
    Serial.println(bluetoothData);
    if(bluetoothData == 'F'){
      Serial.println("Move forward");
      moveForward();
    }
    else if(bluetoothData == 'B'){
      moveReverse();
    }
    else if(bluetoothData == 'R'){
      turnRight();
    }
    else if(bluetoothData == 'L'){
      turnLeft();
    }
    else if(bluetoothData == 'S'){
      stopMoving();
    }
  }
}
void turnRight(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void turnLeft(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
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

void stopMoving(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
