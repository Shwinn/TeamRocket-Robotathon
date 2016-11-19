#define  FRONT_TRIG PD_6
#define FRONT_ECHO PC_7
#define RIGHT_TRIG PB_6
#define RIGHT_ECHO PB_7
#include <Servo.h> 
Servo s1; 
Servo s2; 
void setup(){
pinMode(FRONT_TRIG, INPUT);
pinMode(FRONT_ECHO,OUTPUT);
pinMode(RIGHT_TRIG, INPUT);
pinMode(RIGHT_ECHO,OUTPUT);
Serial.begin(9600);
delay(100); 
s1.attach(PB_0); 
s2.attach(PB_1); 
}
void loop(){
Serial.println(irRead(FRONT_TRIG, FRONT_ECHO)); //display the results
  delay(10); //wait for the string to be sent
}
int irRead(int readPin, int triggerPin)
{
  int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
  int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond
  int i;
  for (i=0; i <=cycles; i++)
  {
    digitalWrite(triggerPin, HIGH); 
    delayMicroseconds(halfPeriod);
    digitalWrite(triggerPin, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }
  return digitalRead(readPin);
}

//if (wall on the right but no wall on the front){
//  if (distance to right wall is decreasing> threshold){
//    turn left a little
//  }
//  if (distance to right wall is increasing> threshold){
//    turn right a little
//  }
//}
//if(no wall on right){
//  turn right 90 degrees
//}
//if(wall on the right and front){
//  turn left 90 degrees
//}
