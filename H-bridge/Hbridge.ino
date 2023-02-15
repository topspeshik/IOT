#include <Servo.h>
#define motor_pin 11
#define motor_pin1 10
Servo servo;
void setup() {
  Serial.begin(9600);
  pinMode(motor_pin, OUTPUT);
  pinMode(motor_pin1, OUTPUT);
}

void switch_motor(bool vector = 0, int speed = 255){
  if (vector){
    
    analogWrite(motor_pin, speed);
  }
  else if (!vector){
    analogWrite(motor_pin1, speed);
  }
    
}

void loop() {
  switch_motor(1, 125);
  
  
}