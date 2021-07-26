
#define DT A0
#define SCK A1
#define sw 9

long sample=0;
float val=0;
long count=0;

void setup()
{
  Serial.begin(9600);
pinMode(SCK, OUTPUT);
pinMode(sw, INPUT_PULLUP);
Serial.print("Weight Measurement");
delay(1000);
calibrate();
}

void loop()
{
count= readCount();
int w=(((count-sample)/val)-2*((count-sample)/val));
Serial.print("Measured weight : ");
Serial.print(w);
Serial.println("g ");
if(digitalRead(sw)==0)
{
val=0;
sample=0;
w=0;
count=0;
calibrate();
}
}

void calibrate()
{
Serial.println("calibrating ....please Wait...");
for(int i=0;i<100;i++)
{
count=readCount();
sample+=count;
}
sample/=100;
Serial.println("put 1250g and Wait");
count=0;
while(count<1000)
{
count=readCount();
count=sample-count;
}
Serial.println("please Wait");
delay(2000);
for(int i=0;i<600;i++)
{
count=readCount();
val+=sample-count;
}
val=val/600.0;
val=val/600.0; // put here your calibrating weight
}

unsigned long readCount(void)
{
unsigned long Count;
unsigned char i;
pinMode(DT, OUTPUT);
digitalWrite(DT,HIGH);
digitalWrite(SCK,LOW);
Count=0;
pinMode(DT, INPUT);
while(digitalRead(DT));
for (i=0;i<24;i++)
{
digitalWrite(SCK,HIGH);
Count=Count<<1;
digitalWrite(SCK,LOW);
if(digitalRead(DT))
Count++;
}
digitalWrite(SCK,HIGH);
Count=Count^0x800000;
digitalWrite(SCK,LOW);
return(Count);
}
