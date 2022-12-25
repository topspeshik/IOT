#include <SoftwareSerial.h>

#define A  7
#define B  6
#define C  8
#define D  10
#define E  11
#define F  12
#define G  13
#define DP  9



SoftwareSerial mySerial(3, 2);

void show(int number){
  if (number == 0){
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
  }else if(number == 1){
    digitalWrite(A, LOW); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
  }else if(number == 2){
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
  }else if(number == 3){
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
  }else if(number == 4){
    digitalWrite(A, LOW); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
  }else if(number == 5){
    digitalWrite(A, HIGH); 
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
  }else if(number == 6){
    digitalWrite(A, HIGH); 
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
  }else if(number == 7){
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
  }else if(number == 8){
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
  }else if(number == 9){
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
  }
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  for (int i = 6; i <= 13; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  if (Serial.available() >= 1){
    int num = 0;
    byte data = Serial.read();
    if (data >= '0' && data <= '9'){
      num = data - '0';
    }
    show(num);
    delay(50);
    if (Serial.available() >= 1){
      while (Serial.available() >= 1){
        mySerial.write(Serial.read());
      }
    }else{
      mySerial.write(byte(0));
    }
  }
}
