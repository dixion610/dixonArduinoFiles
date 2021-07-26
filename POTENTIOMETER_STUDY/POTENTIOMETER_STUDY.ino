int button = 10;
int red = 11;
int green = 12;
int blue = 13;
int ledColor;
int potValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(button,INPUT);
  pinMode(A5,INPUT);
}

void loop() {
  potValue = analogRead(A5);
  Serial.println(potValue);
  delay(60);
  if(potValue <= 500)
    lightAllLed(HIGH);
  else if(potValue > 500 && potValue <= 700){
    lightAllLed(LOW);
    lightRed();
  }
    else if(potValue > 700 && potValue <= 800){
    lightAllLed(LOW);
    lightGreen();
  }
    else if(potValue > 800 && potValue <= 900){
    lightAllLed(LOW);
    lightBlue();
  }
    else if(potValue > 900 && potValue <= 1000){
    lightAllLed(HIGH);
    delay(50); 
    lightAllLed(LOW);
    delay(50);
  }
  else
    lightAllLed(LOW);
}

void selectLedColor(int colorOfLed, boolean stateOfLed ){
  digitalWrite(colorOfLed,stateOfLed);
}

void lightAllLed(boolean ledState){
  selectLedColor(red,ledState);
  selectLedColor(green,ledState);
  selectLedColor(blue,ledState);
}
void lightRed(){
  selectLedColor(red,HIGH);
}

void lightGreen(){
  selectLedColor(green,HIGH);
}

void lightBlue(){
  selectLedColor(blue,HIGH);
}
