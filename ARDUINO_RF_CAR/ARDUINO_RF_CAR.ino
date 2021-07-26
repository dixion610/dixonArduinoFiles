#include <RH_ASK.h>
#include <SPI.h> 
#define IN1 8
#define IN2 9
#define IN3 6
#define IN4 7
RH_ASK rf_driver;
char *rfData;
String data;
void setup() {
  Serial.begin(9600);
  rf_driver.init();
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  uint8_t buf[11];
  uint8_t buflen = sizeof(buf);

if (rf_driver.recv(buf, &buflen)){
      // Message received with valid checksum
    Serial.print("Message Received: ");
    rfData = (char*)buf;
    //Serial.println((char*)buf);
    Serial.println((String)(char*)rfData);
    data = (String)(char*)rfData;
}
    Serial.println(data);
    if(data == "F"){
      Serial.println("Move forward");
      moveForward();
    }
    else if(data == "B"){
      Serial.println("Move BackWard");
      moveReverse();
    }
    else if(data == "R"){
      Serial.println("turn right");
      turnRight();
    }
    else if(data == "L"){
      Serial.println("turn left");
      turnLeft();
    }
    else if(data == "S"){
      Serial.println("stop moving");
      stopMoving();
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
