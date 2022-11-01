#define DATA_PIN 2
#define LETTER_SEP 3
#define DATA_LEVEL LOW
#define IDLE_TIME 10



long start = 0;
int TU = 1000;
int timings[20];
bool levels[20];
int current = 0;
char data_hash[20];
bool check_letter = false;
bool is_idle = false;
String ENCODED[] = {".-", "--.."};
String LETTERS[] = {"A", "Z"};

int n_letter = 2;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(0,process_timing, CHANGE); // 0 - digit pin 2
}

void loop() {

  process_idle();
  if (check_letter){
    decode_letter();
  }
}


void decode_letter(){
  String letter;
  if (timings[current-1] >= LETTER_SEP && levels[current-1] == HIGH ){
      int j = 0;
      for (int i = 0; i < current; i++){
        if (timings[i] == 1 and levels[i] == DATA_LEVEL){
          letter += '.';
          j++;
      }else if (timings[i] == 3 and levels[i] == DATA_LEVEL){
        letter += '-';
          j++;
      }
    }
    current = 0;
    for (int iletter = 0;  iletter < n_letter; iletter++){
      if (ENCODED[iletter] == letter){
        Serial.print(LETTERS[iletter]);
      }
    }
  }
}


void process_timing(){
  if (not is_idle){
    timings[current] = round(millis() - start) / TU;
    levels[current] = !digitalRead(DATA_PIN);
    current++;
    
    check_letter = true;
  }
  start = millis();
  is_idle - false;
}


void process_idle(){
  if (not is_idle and round(millis() - start) / TU >= IDLE_TIME){
    timings[current] = round(millis() - start) / TU;
    levels[current] = !digitalRead(DATA_PIN);
    current++;
    start = millis();
    check_letter = true;
  }
  
}
