int red = 11;
int green = 12;
int blue = 13;
int ledColor = red;

void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  /*if(ledColor >= red && ledColor <= green){
  selectLedColor(ledColor,HIGH);
  delay(1000);
  selectLedColor(ledColor,LOW);
  delay(1000);
  ledColor++;
  }
  else {
    lightAllLed();
    ledColor = red;
  }*/
  lightAllLed();
}

void selectLedColor(int colorOfLed, boolean stateOfLed ){
  digitalWrite(colorOfLed,stateOfLed);
}

void lightAllLed(){
  selectLedColor(red,HIGH);//r+g+b #white
  selectLedColor(green,HIGH);
  selectLedColor(blue,HIGH);
  delay(5000);
  selectLedColor(red,LOW);//g+b 
  delay(5000);
  selectLedColor(red,HIGH);//r+b 
  selectLedColor(green,LOW);
  delay(5000);
  selectLedColor(green,HIGH);//r+g 
  selectLedColor(blue,LOW);
  delay(5000);
  
}
