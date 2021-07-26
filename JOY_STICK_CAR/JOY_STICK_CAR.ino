#define VRx A4
#define VRy A5
#define joySwitch 4
#define IN1 8
#define IN2 9
#define IN3 6
#define IN4 7
#define enableMotorOne 10
#define enableMotorTwo 11
int xAxisValue;
int yAxisValue;
int mapForward;
int mapReverse;
int mapRight;
int mapLeft;
boolean switchValue;
void setup() {
  Serial.begin(9600);
  pinMode(VRx,INPUT);
  pinMode(VRy,INPUT);
  pinMode(enableMotorOne,OUTPUT);
  pinMode(enableMotorTwo,OUTPUT);
  pinMode(joySwitch,INPUT);
}

void loop() {

  switchValue = digitalRead(joySwitch);
  while(switchValue == 1){
  xAxisValue = analogRead(VRx);
  yAxisValue = analogRead(VRy);
  Serial.print(" x axis value : ");
  Serial.println(xAxisValue);
  mapForward = map(xAxisValue,524,1023,0,255);
  mapReverse = map(xAxisValue,524,0,0,255);
  mapRight = map(yAxisValue,509,1023,0,255);
  mapLeft = map(yAxisValue,509,0,0,255);
  if(mapForward > 4){
    moveForward(mapForward);
    Serial.println("move Forward");
  }
  else if(mapReverse > 5){
    moveReverse(mapReverse);
    Serial.println("move Backwards");
  }
  else if(mapRight > 5){
    turnRight(mapRight);
    Serial.println("turn right");
  }
  else if(mapLeft >5){
    turnLeft(mapLeft);
    Serial.println("turnLeft");
  }
  else{
  stopMoving();
  Serial.println("please Stop moving");
  }
  
  Serial.print("forwardValue : ");
  Serial.println(mapForward);
  Serial.print("reverseValue : ");
  Serial.println(mapReverse);
  Serial.print(" y axis value : ");
  Serial.println(yAxisValue);

  Serial.print("rightValue : ");
  Serial.println(mapRight);
  Serial.print("leftValue : ");
  Serial.println(mapLeft);
  switchValue = digitalRead(joySwitch);
  }
  Serial.println("stop moving");
  stopMoving();

}
void turnRight(int speedOfMotor){
  analogWrite(enableMotorOne,speedOfMotor);
  analogWrite(enableMotorTwo,speedOfMotor);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void turnLeft(int speedOfMotor){
  analogWrite(enableMotorOne,speedOfMotor);
  analogWrite(enableMotorTwo,speedOfMotor);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void moveForward(int speedOfMotor){
  analogWrite(enableMotorOne,speedOfMotor);
  analogWrite(enableMotorTwo,speedOfMotor);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void moveReverse(int speedOfMotor){
  analogWrite(enableMotorOne,speedOfMotor);
  analogWrite(enableMotorTwo,speedOfMotor);
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
