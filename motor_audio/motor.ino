#define motor_pin 10

void setup() {
  pinMode(motor_pin, OUTPUT);
}

void loop() {
  for(int velocity=0; velocity <= 255; velocity++){
      analogWrite(motor_pin, velocity);
      delay(10);
    }
}
