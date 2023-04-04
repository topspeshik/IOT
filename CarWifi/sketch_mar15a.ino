#include <SoftwareSerial.h>

#define motorRight1 4
#define motorRight2 5
#define motorLeft1 6
#define motorLeft2 7
SoftwareSerial mySerial(0, 1);

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);
}

void loop() {
  if (mySerial.available() > 0) {
    char msg = (char)mySerial.read();
    Serial.write(msg);

    if (msg == 'f') {
      forward();
    }
    else if (msg == 'b') {
      backward();
    }
    else if (msg == 'r') {
      turn_right();
    }
    else if (msg == 'l') {
      turn_left();
    }
    else if (msg == 's') {
      stop();
    }
  }
}

void forward() {
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, 250);
  digitalWrite (motorRight1, LOW);
  analogWrite (motorRight2, 250);
}
void backward() {
  digitalWrite (motorLeft2, LOW);
  analogWrite (motorLeft1, 250);
  digitalWrite (motorRight1, HIGH);
  analogWrite (motorRight2, 250);
}
void turn_right() {
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, 250);
  digitalWrite (motorRight1, HIGH);
  analogWrite (motorRight2, 150);
}
void turn_left() {
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, 150);
  digitalWrite (motorRight1, LOW);
  analogWrite (motorRight2, 250);
}
void stop() {
  analogWrite(motorLeft1, 0);
  analogWrite(motorRight2, 0);
}
