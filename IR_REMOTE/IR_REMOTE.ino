#include <IRremote.h>
#include <Servo.h>

#define servoPin 8
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
String value;
Servo servo;

void setup(){
  servo.attach(servoPin);
  servo.write(0);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        if(results.value == 0xFF02FD){
          Serial.println("0 degree");
          servo.write(0);
        }
        else if(results.value == 0xFFA857){
          Serial.println("90 degree");
          servo.write(90);
        }
        else if(results.value == 0xFF9867){
          Serial.println("180 degree");
          servo.write(179);
        }
        irrecv.resume();
  }
}
