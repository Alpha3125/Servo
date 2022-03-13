#include <Servo.h>
Servo servo;
int pin=9;


void setup()
{
 Serial.begin(9600);
 servo.attach(pin);
}

void type1(int pos1=20,int pos2=80,int gap=1000)
{
 servo.write(pos1);
 delay(gap);
 servo.write(pos2);
}

void type2(int pos1=10,int pos2=80,int gap=2000,int interval=200)
{
  int ticks=gap/interval;
  int initial=servo.read();
  int turn=(pos1-initial)/ticks;
  for(int i=1;i<=ticks;i++)
  {
    delay(interval);
    servo.write(initial + i*turn);
  }
  delay(gap);
  servo.write(pos2);
}

void loop()
{
 type1();
 delay(2000);
 type2();
 delay(6000);
}
