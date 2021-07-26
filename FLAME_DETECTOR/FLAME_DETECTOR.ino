#define flameSensorPin 8
#define pumpPin 10
int flameSensorPinValue;
String digitalMsg = "Digital value is :";
String digitalSenseFlame = "digital sensor detected flame.";
void setup() {
  Serial.begin(9600);
  pinMode(flameSensorPin,INPUT);
  pinMode(pumpPin,OUTPUT);
  digitalWrite(pumpPin,HIGH);
}

void loop() {
  flameSensorPinValue = digitalRead(flameSensorPin);
  Serial.print(digitalMsg);
  Serial.print(flameSensorPinValue);
  Serial.println("");
  if(flameSensorPinValue == 1){
    digitalWrite(pumpPin,LOW);
  }
  else{
    digitalWrite(pumpPin,HIGH);
  }
  delay(500);
}
