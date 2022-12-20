#define DATA_PIN 2
#define LETTER_SEP 3
#define IDLE_SEP 10
#define DATA_LEVEL LOW

int TU = 1000;
long start = 0;

int timings[20];
bool levels[20];
int current = 0;
bool check_letters = false;
bool is_idle = false;

String ENCODED[] = {".-", "--.."};
String LETTERS[] = {"A", "Z"};
int n_letters = 2;

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, INPUT);
  attachInterrupt(0, process_timing, CHANGE);
}

void loop() {
  Serial.println(current);
  process_idle();
  if (check_letters){
    process_letter();
    check_letters = false;
  }
}


void process_letter(){
  if (timings[current - 1] >= LETTER_SEP && levels[current - 1] == HIGH){
    String letter = "";
    for (int i = 0; i < current; i++){
      if (timings[i] == 1 && levels[i] == DATA_LEVEL){
        letter  += ".";
      }
      else if (timings[i] == 3 && levels[i] == DATA_LEVEL){
        letter += ",";
      }
    }
    current = 0;
    for (int iletter=0; iletter < n_letters; iletter++){
      if (letter == ENCODED[iletter]){
        Serial.println(LETTERS[iletter]);
      }
    }
  }
}

void process_timing(){
  if (!is_idle){
    timings[current] = millis() - start;
    levels[current] = !digitalRead(DATA_PIN);
    current++;
    check_letters = true;
  }
  
  start = millis();
  is_idle = false;
}


void process_idle(){
  if (!is_idle && timings[current - 1] >= IDLE_SEP){
    timings[current] = millis() - start;
    levels[current] = 1;
    current++;
    start = millis();
    check_letters = true;
    is_idle = true;
  }
}
