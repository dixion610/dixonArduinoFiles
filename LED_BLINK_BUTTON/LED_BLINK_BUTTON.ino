int button = 10;
int red = 11;
int green = 12;
int blue = 13;
int ledColor = red;
boolean buttonValue = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(button,INPUT);
  pinMode(A5,INPUT);
}

void loop() {
  buttonValue = digitalRead(button);
  //Serial.println(buttonValue);
  lightAllLed(buttonValue);
}

void selectLedColor(int colorOfLed, boolean stateOfLed ){
  digitalWrite(colorOfLed,stateOfLed);
}

void lightAllLed(boolean ledState){
  selectLedColor(red,ledState);
  if(ledState == 0)
  Serial.println("OFF");
  else
  Serial.println("RED");
  /*selectLedColor(green,ledState);
  selectLedColor(blue,ledState);*/
}
