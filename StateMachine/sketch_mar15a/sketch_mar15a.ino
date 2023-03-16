#define wheel_left1 4
#define wheel_left2 5
#define wheel_right1 6
#define wheel_right2  7
#define vcc 13
#define trig 11
#define echo 12
#define IPin A0

bool go = false;
bool rotL = false;
bool rotR = false;

float minL = 15;
float maxL = 20;
float minF = 15;
float ldist = 0;
float ffist = 0;


void setup() {
  Serial.begin(9600);
  pinMode(wheel_left1, OUTPUT);
  pinMode(wheel_left2, OUTPUT);
  pinMode(wheel_right2, OUTPUT);
  pinMode(wheel_right1, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(IPin, INPUT);
  digitalWrite(vcc, HIGH);

  
}


void loop() {
  float volts = analogRead(IPin) * 0.0048828125;
  ffist = 32 * pow(volts, -1.10);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  ldist = (pulseIn(echo, HIGH) / 2) / 29.1;
  
  
  update_states();
  do_action();
  delay(150);
}


void update_states(){
  if (ldist > maxL) {
    rotR = false;
    rotL = true;
    go = false;
  } else if ((ffist < minF) or (ldist < minL)) {
    rotR = true;
    rotL = false;
    go = false;
  } 
  else if(ldist< minL) {
    go = true;
    rotR = false;
    rotL = false;
  }
  else {
    rotR = false;
    rotL = false;
    go = false;
  }

}


void do_action(){
  if (go) {
    digitalWrite(wheel_right2, LOW);
    analogWrite(wheel_right1, 200);
    digitalWrite(wheel_left1, HIGH);
    analogWrite(wheel_left2, 200);
  } else if (rotR) {
    analogWrite(wheel_right1, 150);
    digitalWrite(wheel_right2, LOW);
    analogWrite(wheel_left2, 150);
    digitalWrite(wheel_left1, LOW);
  } else if (rotL) {
   analogWrite(wheel_right1, 150);
    digitalWrite(wheel_right2, HIGH);
    analogWrite(wheel_left2, 150);
    digitalWrite(wheel_left1, HIGH);

  } else {
    analogWrite(wheel_right1, 0);
    analogWrite(wheel_left2, 0);
  }
}
