#define redPin 2
#define loadRelayPin 6
#define solarRelayPin 11
#define greenPin 3 
#define bluePin 4
#define loadStatePin 7
#define pwmPin 9 
#define buckEnablePin 10 
#define inputVoltagePin A1
#define inputCurrentPin A0
#define batteryVoltagePin A2
#define maxBatteryVoltage 14.00
#define minBatteryVoltage 10.30
#define highBatteryVoltage 13.60
#define fullCharge 14.20
#define minSolarVoltage 10.00
#define cutOffPower 5.00
#define minSolarVolt 2.00
#define loadOnSolarVoltage 5.00// voltage of solar panel at which the load turns on
#include <avr/wdt.h>

int voltageBitsIn;
int voltageBitsOut;
float solarInputVoltage;
float solarInputCurrent;
float offsetCurrent;
float inputPower;
float previousPower; 
float batteryVoltage;
float previousBatteryVoltage;
float pwm;
float dutyCycle;
float delta;
float deltaBattery;
boolean loadState = LOW;
unsigned long previousMillis = 0; // last time update
long interval = 3600000; // interval for reset
extern volatile unsigned long timer0_millis;
enum chargerState{
  mppt,
  off,
  on,
  loadOn,
  constantVoltage,
  lowbattery,
  fullbattery,
  standby
};
chargerState stateOfCharger = off;

void setup() {
  InitSetup();
}

void InitSetup()
{
  voltageBitsOut = 0;
  solarInputVoltage=0.0;
  solarInputCurrent = 0.0;
  offsetCurrent = 0.0;
  inputPower = 0.0;
  previousPower = 0.0; 
  batteryVoltage = 0.0;
  previousBatteryVoltage = 0.0;
  pwm = 0.0;
  dutyCycle = 0.0;
  delta = 0.5;
  deltaBattery = 0.5;
  stateOfCharger = on;
  previousMillis = 0;
  noInterrupts ();
  timer0_millis = 0;
  interrupts ();

  pinMode(buckEnablePin,OUTPUT);
  pinMode(loadRelayPin,OUTPUT);
  pinMode(solarRelayPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(loadStatePin,INPUT_PULLUP);
  analogReference(EXTERNAL);
  getOffsetCurrent();
  TCCR1B = TCCR1B & B11111000 | B00000001;
  pwm = 70;
  enableBuckConverter();
  initialize();
  getInputParameters();
  loadState = digitalRead(loadStatePin);
}

void softwareReset( uint8_t prescaller) {
  // start watchdog with the provided prescaller
  wdt_enable( prescaller);
  // wait for the prescaller time to expire
  // without sending the reset signal by using
  // the wdt_reset() method
  while(1) {}
}

void getOffsetCurrent(){
  offsetCurrent = averageAdcValue(inputCurrentPin,100)*0.0073758496978852; 
}

void getInputParameters(){
  solarInputVoltage = averageAdcValue(inputVoltagePin,25)*0.02685546875;//0.026640625;//0.0146627565982405;//0.029296875;//voltageBitsIn*((float)refVal/1023)*12;
  solarInputCurrent = averageAdcValue(inputCurrentPin,25)*0.0073758496978852 - offsetCurrent;//0.0073168429003021148036253776435;//0.0024437927663734/(0.331*0.001)=0.0073830597171402;0.002421875//analogValue * 2.5/1023
  if(solarInputCurrent < 0.0){
    solarInputCurrent = 0.0;
  }
  inputPower = solarInputVoltage*solarInputCurrent;
  batteryVoltage = averageAdcValue(batteryVoltagePin,25)*0.01466275659824046920821114369501;//0.01453125;
}

int averageAdcValue(int adcPin,int compareVariable){
  for(int i=0; i<=3;i++){
   analogRead(adcPin); 
   delay(1);
  }
  int sumOfReadings = 0;
  for(int i=0; i<compareVariable;i++){
     sumOfReadings += analogRead(adcPin);
  }
  return sumOfReadings/compareVariable;
}

void performMPPT(){
        if (previousPower <= inputPower && pwm <= 74.00) {                   // if previous watts are greater change the value of
          pwm += deltaBattery;                  // delta to make pwm increase or decrease to maximize watts
        }
        if(previousPower > inputPower && pwm >= 70.00){
          pwm -=deltaBattery;
        }
        previousPower = inputPower;                          // load old_watts with current watts value for next time
        setPwmDutyCycle();
        delay(150);
}

void performCv(){
   if (batteryVoltage < maxBatteryVoltage && pwm <=74.00) {// if previous watts are greater change the value of
          pwm += delta;                  // delta to make pwm increase or decrease to maximize watts
        }
   if(batteryVoltage >= maxBatteryVoltage && pwm >= 70.00){
          pwm -=delta;
        }
   previousBatteryVoltage = batteryVoltage;// load old_watts with current watts value for next time
   setPwmDutyCycle();
   delay(150);
   if(batteryVoltage >= fullCharge){
    while(batteryVoltage > highBatteryVoltage){
      loadState = digitalRead(loadStatePin);
      disableBuckConverter();
      getInputParameters();
      if(solarInputVoltage < minSolarVoltage && solarInputVoltage > loadOnSolarVoltage ){
        break;
      }
      else if(solarInputVoltage < loadOnSolarVoltage){
        break;
      }
      else if(loadState == HIGH){
        turnLoadRelayOff();
        break;
      }
    }
   }
}

void setPwmDutyCycle(){
  dutyCycle = 1023.0*pwm/100.0;
  analogWrite(pwmPin,dutyCycle);
}

void lowbatteryBlink(){
  for(int i = 0; i <= 10; i++){
    redOn();
    delay(200);
    rbgOff();
    delay(200);
  }  
  }

  void fullbatteryBlink(){
  for(int i = 0; i <= 20; i++){
    greenOn();
    delay(3000);
    redOn();
    delay(3000);
    blueOn();
    delay(3000);
  }  
  }

  void standbyMode(){
  for(int i = 0; i <= 10; i++){
    greenOn();
    delay(500);
    blueOn();
    delay(300);
  }  
  }

void initialize(){
          turnSolarRelayOff();
          turnLoadRelayOff();
          disableBuckConverter();
          greenOn();
          delay(2000);
  }

void performCharging(){

         //StandBy Avoid Flickering
         if(solarInputVoltage >= (loadOnSolarVoltage - 1) && solarInputVoltage <= (loadOnSolarVoltage + 1)){
          standbyMode();
          initialize();
          stateOfCharger = standby;
          return;
         } 

         //LOAD ON
         if(solarInputVoltage < loadOnSolarVoltage && batteryVoltage > minBatteryVoltage){
          if(stateOfCharger != loadOn){
          blueOn();
          turnLoadRelayOn();
          stateOfCharger = loadOn;
          }
         }         
         
         //MPPT
         else if(batteryVoltage < highBatteryVoltage && solarInputVoltage > minSolarVolt){
          if(stateOfCharger != mppt){

            //LoadOn To MPPT Change Reset
           if(stateOfCharger == standby){
            //Reset Function
            softwareReset( WDTO_60MS);}
            
            turnSolarRelayOn();
            enableBuckConverter();
            redOn();
            stateOfCharger = mppt;
            }
            performMPPT();
            ResetByInterval();
         }

         //Constant Voltage
         else if(batteryVoltage >= highBatteryVoltage){
          greenOn();
          performCv();
          if(batteryVoltage < highBatteryVoltage){
            standbyMode();
            stateOfCharger = standby;
            return;
            }
            else{
              stateOfCharger = constantVoltage;
              }
         }

         //Charger Off or Low Battery
         else if(batteryVoltage <= minBatteryVoltage){
          lowbatteryBlink();
          initialize();
          stateOfCharger = lowbattery;
         }
         
        // Full Charge Cut Off
        else if(batteryVoltage >= fullCharge){
          fullbatteryBlink();
          stateOfCharger = fullbattery;
          }
}

void ResetByInterval(){
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {

    //Reset Previous Millis
     previousMillis = 0;

     //Reset Millis
     noInterrupts ();
     timer0_millis = 0;
     interrupts ();  

     //Reset Function
     softwareReset( WDTO_60MS);
  }
  }

void enableBuckConverter(){
  digitalWrite(buckEnablePin,HIGH);
}

void disableBuckConverter(){
  digitalWrite(buckEnablePin,LOW);
}

void turnSolarRelayOn(){
  digitalWrite(solarRelayPin,HIGH);
}

void turnSolarRelayOff(){
  digitalWrite(solarRelayPin,LOW);
}

void turnLoadRelayOn(){
  digitalWrite(loadRelayPin,HIGH); 
}

void turnLoadRelayOff(){
  digitalWrite(loadRelayPin,LOW); 
}

void redOn(){
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
}

void greenOn(){
  digitalWrite(greenPin,HIGH);
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,LOW);
}

void blueOn(){
  digitalWrite(bluePin,HIGH);
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,LOW);
}

void rbgOff(){
  digitalWrite(bluePin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,LOW);
  }


void loop() {
  getInputParameters();
  loadState = digitalRead(loadStatePin);
  if(batteryVoltage > 0.00){
    performCharging();
    
    //Load On/Off
    loadOnOff(); 
  }
  else{ 
  turnSolarRelayOff();
  turnLoadRelayOff();
  greenOn();
  }
}

void loadOnOff(){
  if(loadState == LOW){
    turnLoadRelayOn();
    }
  else if(loadState == HIGH && solarInputVoltage > loadOnSolarVoltage) {
    turnLoadRelayOff();
    }
  }
