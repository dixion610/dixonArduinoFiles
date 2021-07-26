int button = 10;
int red = 11;
int green = 12;
int blue = 13;
int ledColor;
int potValue = 0;
int mapValue = 0;

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
  mapValue = map(potValue,0,1023,0,255);
  analogWrite(red,mapValue);
}
