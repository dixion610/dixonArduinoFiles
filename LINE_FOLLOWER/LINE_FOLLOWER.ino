#define IN1 8
#define IN2 9
#define IN3 12
#define IN4 7
#define enablePinOne 6
#define enablePinTwo 11
#define S1 2
#define S2 3
#define S3 4
#define S4 10
#define S5 5
String sw1;
String sw2;
String sw3;
String sw4;
String sw5;
String switchValue;
unsigned int switchVariable;
void setup() {
  Serial.begin(9600);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(S5,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(enablePinOne,OUTPUT);
  pinMode(enablePinTwo,OUTPUT);
}

void loop() {
  sw1 = digitalRead(S1);
  sw2 = digitalRead(S2);
  sw3 = digitalRead(S3);
  sw4 = digitalRead(S4);
  sw5 = digitalRead(S5);
  switchValue = sw1+sw2+sw3+sw4+sw5;
  Serial.println(switchValue);
  switchVariable = switchValue.toInt();
  // case 1
  while(switchValue == "00000"){
    stopMoving();
    while(1){}
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 2
  while(switchValue == "00001"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }  

  // case 3
  while(switchValue == "00010"){
    turnLeft(190,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 4
  while(switchValue == "00011"){
    turnLeft(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 5
  while(switchValue == "00100"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }  

  // case 6
  while(switchValue == "00101"){
    turnLeft(100,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 7
  while(switchValue == "00110"){
    turnLeft(90,200);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 8
  while(switchValue == "00111"){
    moveForward(80,200);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 9
  while(switchValue == "01000"){
    turnRight(250,80);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

   // case 10
   while(switchValue == "01001"){
    moveForward(200,80);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

 // case 11
  while(switchValue == "01010"){
    turnRight(255,100);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }
 // case 12
  while(switchValue == "01011"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

 // case 13
  while(switchValue == "01100"){
    turnRight(255,120);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 14
  while(switchValue == "01101"){
    turnLeft(190,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 15
  while(switchValue == "01110"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 16
  while(switchValue == "01111"){
    turnLeft(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 17
  while(switchValue == "10000"){
    stopMoving();
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 18
  while(switchValue == "10001"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 19
  while(switchValue == "10010"){
    turnRight(190,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 20
  while(switchValue == "10011"){
    moveForward(80,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 21
  while(switchValue == "10100"){
    turnRight(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 22
  while(switchValue == "10101"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 23
  while(switchValue == "10110"){
    turnRight(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 24
  while(switchValue == "10111"){
    moveForward(80,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 25
  while(switchValue == "11000"){
    turnRight(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 26
  while(switchValue == "11001"){
    moveForward(255,80);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 27
  while(switchValue == "11010"){
    turnRight(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 28 //move forward
  while(switchValue == "11011"){
    moveForward(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 29
  while(switchValue == "11100"){
    turnRight(255,190);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 30
  while(switchValue == "11101"){
    moveForward(255,80);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

  // case 31
  while(switchValue == "11110"){
    turnRight(255,255);
    sw1 = digitalRead(S1);
    sw2 = digitalRead(S2);
    sw3 = digitalRead(S3);
    sw4 = digitalRead(S4);
    sw5 = digitalRead(S5);
    switchValue = sw1+sw2+sw3+sw4+sw5;
  }

    // case 32
  while(switchValue == "11111"){
    turnLeft(255,255);
    while(switchValue == 01111){
            sw1 = digitalRead(S1);
            sw2 = digitalRead(S2);
            sw3 = digitalRead(S3);
            sw4 = digitalRead(S4);
            sw5 = digitalRead(S5);
        switchValue = sw1+sw2+sw3+sw4+sw5;
      }
            sw1 = digitalRead(S1);
            sw2 = digitalRead(S2);
            sw3 = digitalRead(S3);
            sw4 = digitalRead(S4);
            sw5 = digitalRead(S5);
        switchValue = sw1+sw2+sw3+sw4+sw5;
    }
 


  
  /*switch (switchVariable) {
    case 0: Serial.println("case 1");
            stopMoving();
            delay(100);
            break;
    case 1: Serial.println("case 2");
            turnLeft(255,255);
            delay(100);
            break;
    /*case 10: Serial.println("case 3");
            break;
    case 11: Serial.println("case 4");
            turnLeft(255,255);
            delay(100);
            break;
    /*case 100: Serial.println("case 5");
            break;
    case 101: Serial.println("case 6");
            break;
    case 110: Serial.println("case 7");
            break;                                                                        
    case 111: Serial.println("case 8");//move left fast
            moveForward(80,200);
            break;
    /*case 1000: Serial.println("case 9");
            break;
    case 1001: Serial.println("case 10");
            break;
    case 1010: Serial.println("case 11");
            break;
    case 1011: Serial.println("case 12");
            break;
    case 1100: Serial.println("case 13");
            break;
    case 1101: Serial.println("case 14");
            break;
    case 1110: Serial.println("case 15");
            break;
    case 1111: Serial.println("case 16");//move sharp left
            turnLeft(255,255);
            break;
    case 10000: Serial.println("case 17");
            moveForward(255,80);
            break;
    /*case 10001: Serial.println("case 18");
            break;
    case 10010: Serial.println("case 19");
            break;
    case 10011: Serial.println("case 20");//move left slightly
            moveForward(80,250);
            break;
    /*case 10100: Serial.println("case 21");
            break;
    case 10101: Serial.println("case 22");
            break;                                                                                                                                                                                    
    case 10110: Serial.println("case 23");
            break;
    case 10111: Serial.println("case 24"); 
            moveForward(255,0);
            break;
    case 11000: Serial.println("case 25");
            moveForward(255,0);
            break;
    case 11001: Serial.println("case 26");//move right slightly
            moveForward(220,80);
            break;
    /*case 11010: Serial.println("case 27");
            break;
    case 11011: Serial.println("case 28");//move straight
            moveForward(255,190);
            break;
    case 11100: Serial.println("case 29");
            moveForward(255,80);
            break;
   case 11101: Serial.println("case 30");
            moveForward(255,0);
            break;
    case 11110: Serial.println("case 31");//turn sharp right
            turnRight(255,255);
            break;
    case 11111: Serial.println("case 32");
            stopMoving();
            break; 
    default: stopMoving();                                                                                                                       
  }*/
  
  Serial.println(switchVariable);
  Serial.println("");

}

void moveForward(int motorOneSpeed,int motorTwoSpeed){
  analogWrite(enablePinOne,motorOneSpeed);
  analogWrite(enablePinTwo,motorTwoSpeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void moveReverse(int motorOneSpeed,int motorTwoSpeed){
  analogWrite(enablePinOne,motorOneSpeed);
  analogWrite(enablePinTwo,motorTwoSpeed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void turnRight(int motorOneSpeed,int motorTwoSpeed){
  analogWrite(enablePinOne,motorOneSpeed);
  analogWrite(enablePinTwo,motorTwoSpeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void turnLeft(int motorOneSpeed,int motorTwoSpeed){
  analogWrite(enablePinOne,motorOneSpeed);
  analogWrite(enablePinTwo,motorTwoSpeed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void stopMoving(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
