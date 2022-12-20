#define DATA_PIN 7
#define DATA_LEVEL LOW
String ENCODED[] = {".-", "--.."};
char LETTERS[] = {'A', 'Z'};
int n_letter = 2;
int TU = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(DATA_PIN, !DATA_LEVEL);
}

void loop() {
  if (Serial.available() >= 1){
    char letter = Serial.read();
    for (int iletter = 0; iletter < n_letter; iletter++){
      if (letter == LETTERS[iletter]){
        encode(ENCODED[iletter]);
      }
    }
  }
}

void encode(String dashdot){
  int len = dashdot.length();
  for (int isymbol = 0; isymbol < len; isymbol++){
    if (dashdot[isymbol] == '.'){
      digitalWrite(DATA_PIN, DATA_LEVEL);
      delay(TU);
      digitalWrite(DATA_PIN, !DATA_LEVEL);
    }
    else if (dashdot[isymbol] == '-'){
      digitalWrite(DATA_PIN, DATA_LEVEL);
      delay(3*TU);
      digitalWrite(DATA_PIN, !DATA_LEVEL);
    }
    delay(TU);
  }
  delay(2 * TU);
}

