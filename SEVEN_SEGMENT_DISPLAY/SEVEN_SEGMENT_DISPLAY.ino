int a = 2, b=3, dot=4, c=5, d=6, e=7, f=8, g=9, numberToDisplay;
void setup() {
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(dot,OUTPUT);
}

void loop() {
 /* if(Serial.available() > 0){
      numberToDisplay = Serial.read();
      Serial.println(numberToDisplay);
  }
  if(numberToDisplay == 48)
  displayZero();
  else
  displayDot();*/
  displayZero();
  delay(1000);
  displayOne();
  delay(1000);
  displayTwo();
  delay(1000);
  displayThree();
  delay(1000);
  displayFour();
  delay(1000);
  displayFive();
  delay(1000);
  displaySix();
  delay(1000);
  displaySeven();
  delay(1000);
  displayEight();
  delay(1000);
  displayNine();
  delay(1000);
  displayDot();
  delay(1000);*/
}

void displayZero(){
  nodeA(HIGH);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(HIGH);
  nodeE(HIGH);
  nodeF(HIGH);
  nodeG(LOW);
  nodeDot(LOW);
}

void displayOne(){
  nodeA(LOW);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(LOW);
  nodeE(LOW);
  nodeF(LOW);
  nodeG(LOW);
  nodeDot(LOW);
}

void displayTwo(){
  nodeA(HIGH);
  nodeB(HIGH);
  nodeC(LOW);
  nodeD(HIGH);
  nodeE(HIGH);
  nodeF(LOW);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displayThree(){
  nodeA(HIGH);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(HIGH);
  nodeE(LOW);
  nodeF(LOW);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displayFour(){
  nodeA(LOW);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(LOW);
  nodeE(LOW);
  nodeF(HIGH);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displayFive(){
  nodeA(HIGH);
  nodeB(LOW);
  nodeC(HIGH);
  nodeD(HIGH);
  nodeE(LOW);
  nodeF(HIGH);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displaySix(){
  nodeA(HIGH);
  nodeB(LOW);
  nodeC(HIGH);
  nodeD(HIGH);
  nodeE(HIGH);
  nodeF(HIGH);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displaySeven(){
  nodeA(HIGH);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(LOW);
  nodeE(LOW);
  nodeF(LOW);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displayEight(){
  nodeA(HIGH);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(HIGH);
  nodeE(HIGH);
  nodeF(HIGH);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displayNine(){
  nodeA(HIGH);
  nodeB(HIGH);
  nodeC(HIGH);
  nodeD(HIGH);
  nodeE(LOW);
  nodeF(HIGH);
  nodeG(HIGH);
  nodeDot(LOW);
}

void displayDot(){
  nodeA(LOW);
  nodeB(LOW);
  nodeC(LOW);
  nodeD(LOW);
  nodeE(LOW);
  nodeF(LOW);
  nodeG(LOW);
  nodeDot(HIGH);
}


void nodeA(boolean ledState) {
    digitalWrite(a,ledState); 
}

void nodeB(boolean ledState){
   digitalWrite(b,ledState); 
}

void nodeC(boolean ledState){
   digitalWrite(c,ledState); 
}

void nodeD(boolean ledState){
   digitalWrite(d,ledState); 
}

void nodeE(boolean ledState){
   digitalWrite(e,ledState); 
}

void nodeF(boolean ledState){
   digitalWrite(f,ledState); 
}

void nodeG(boolean ledState){
   digitalWrite(g,ledState); 
}

void nodeDot(boolean ledState){
   digitalWrite(dot,ledState); 
}
