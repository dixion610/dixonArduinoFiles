#define RS 12
#define E 11
#define D4 10
#define D5 9
#define D6 8
#define D7 7
#define V0 6
#define tempPin A5
#define dhtType DHT11
#define contrastValue 70
#include <LiquidCrystal.h>
#include <DHT.h>
float temperature;
float humidityValue;
String temperatureMsg = "temperature is:";
String humidityMsg = "humidity is";
LiquidCrystal liquidCrystal(RS,E,D4,D5,D6,D7);
DHT dht(tempPin,dhtType);
void setup() {
 Serial.begin(9600);
 dht.begin();
 pinMode(tempPin,INPUT); 
 pinMode(V0,OUTPUT);
 analogWrite(V0,contrastValue);
 liquidCrystal.begin(16,2);
 liquidCrystal.setCursor(0,0);
 liquidCrystal.print("hello");
}

void loop() {
  temperature = dht.readTemperature();
  humidityValue = 
  liquidCrystal.setCursor(0,0);
  liquidCrystal.print(temperatureMsg);
  liquidCrystal.setCursor(0,1);
  liquidCrystal.print(temperature);
  Serial.println(temperature);
  delay(2000);
   liquidCrystal.setCursor(0,0);
  liquidCrystal.print(temperatureMsg);
  liquidCrystal.setCursor(0,1);
  liquidCrystal.print(temperature);
  liquidCrystal.clear();
}
