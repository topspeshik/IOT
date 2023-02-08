#define led_pin3 3
#define led_pin4 4
#define led_pin5 5
#define led_pin6 6

void setup() {
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}

void off(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
}

void one(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}

void two(){
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}

void three(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}

void four(){
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}

void oneTwo(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}
void threeFour(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}
void oneThree(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, HIGH);
}
void twoFour(){
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, HIGH);
}

void oneFour(){
  one();
  delay(5);
  four();
  delay(5);
 
}

void two3(){
  two();
  delay(5);
  three();
  delay(5);
 
}

void one24(){
  one();
  delay(5);
  two();
  delay(5);
  four();
  delay(5);
 
}
void one23(){
  one();
  delay(5);
  two();
  delay(5);
  four();
  delay(5);
 
}

void one34(){
  one();
  delay(5);
  three();
  delay(5);
  four();
  delay(5);
 
}

void one234(){
  one();
  delay(5);
  two();
  delay(5);
  three();
  delay(5);
  four();
  delay(5);
 
}





void loop() {
  one();
}
