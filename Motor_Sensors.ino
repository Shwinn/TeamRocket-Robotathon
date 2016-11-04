#include <Servo.h>
Servo s1;
Servo s2;
#define LED GREEN_LED
////
void setup() {    
  //pinMode(PB_0, OUTPUT);
  //pinMode(PB_1, OUTPUT);               
  s1.attach(PB_0);
  s2.attach(PB_1);
////  //pinMode(PB_0, OUTPUT);
////  //pinMode(PB_1, OUTPUT);
  pinMode(LED,OUTPUT);
}
////
void loop() {
  digitalWrite(LED,HIGH);
  //digitalWrite(PB_0, LOW);
  //digitalWrite(PB_1, LOW);
  s1.write(-90);
  s2.write(180);
  delay(15);  
}
