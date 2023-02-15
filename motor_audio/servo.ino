#include <Servo.h>;
Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  for (int pos=0; pos <= 180; pos++){
    servo.write(pos);
    delay(10);
  }
  for (int pos=180; pos <= 0; pos--){
    servo.write(pos);
    delay(10);
  }
}
