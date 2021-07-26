#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define enablePinOne 6
#define enablePinTwo 9
int delayValue = 3000;
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(enablePinOne,OUTPUT);
  pinMode(enablePinTwo,OUTPUT);
}

void loop() {
  moveForward();
  delay(delayValue);
  moveReverse();
  delay(delayValue);
  turnLeft();
  delay(delayValue);
  turnRight();
  delay(delayValue);
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

void moveMoters(boolean IN1State,boolean IN2State, boolean IN3State, boolean IN4State){
  digitalWrite(IN1,IN1State);
  digitalWrite(IN2,IN2State);
  digitalWrite(IN3,IN3State);
  digitalWrite(IN4,IN4State);
}
