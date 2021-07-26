#define soilMoistureAnalogPin  A4
#define soilMoistureDigitalPin  8
#define pumpPin 10
int soilMoistureDigitalPinValue;
int soilMoistureAnalogPinValue;
String analogMsg = "Analog value is : ";
String digitalMsg = "Digital value is : ";
String analogSenseWaterMsg = "analog sensor detected water in soil.";
String digitalSenseWaterMsg = "digital sensor detected water in soil.";
String senseWaterMsg = "sensor detected water in soil";

void setup() {
  Serial.begin(9600);
  pinMode(soilMoistureAnalogPin,INPUT);
  pinMode(soilMoistureDigitalPin,INPUT);
  pinMode(pumpPin,OUTPUT);
  digitalWrite(pumpPin,HIGH);  
}

void loop() {
  soilMoistureAnalogPinValue = analogRead(soilMoistureAnalogPin);
   Serial.print(analogMsg);
   Serial.print(soilMoistureAnalogPinValue);
   Serial.println("");
  soilMoistureDigitalPinValue = digitalRead(soilMoistureDigitalPin);
  Serial.print(digitalMsg);
  Serial.print(soilMoistureDigitalPinValue);
  Serial.println("");
  if(soilMoistureAnalogPinValue <= 700 || soilMoistureDigitalPinValue == 0 ){
    Serial.println(senseWaterMsg);
    digitalWrite(pumpPin,LOW);
    //pumpWaterOut(HIGH);
  }
  else{
    digitalWrite(pumpPin,HIGH);
    //pumpWaterOut(HIGH);
  }
  delay(1000);
}

void pumpWaterOut(boolean pumpOrNot){
  if(pumpOrNot)
  digitalWrite(pumpPin,LOW);
  else
  digitalWrite(pumpPin,HIGH);
}
