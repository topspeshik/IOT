#define DATA_PIN 2
#define LETTER_SEP 3
#define IDLE_SEP 10
#define DATA_LEVEL LOW

int TU = 1000;
long start = 0;
int prev = HIGH;
long letterMil = 0;
long spaceMil = 0;
int timings[20];
int current = 0;


String ENCODED[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


void setup() {
  Serial.begin(9600);

}

void loop() {
  find_letter();
}


void process_letter(){
  String morse = "";
  for ( int i=0 ; i<current; i++){
    if (timings[i] == 3){
      morse += '-';
    }
    else if (timings[i] == 1){
      morse += '.';
    }
    timings[i] = 0;
  }
  for ( int i = 0; i < 26; i++){
    if (morse == ENCODED[i]){
      Serial.print(LETTERS[i]);
    }
  }
 
  current = 0;
  
}


void find_letter(){
  int currentState = digitalRead(DATA_PIN);
 
  if (currentState == DATA_LEVEL  and prev == HIGH){
    letterMil = millis();
    
    if(int(round((millis()+100-spaceMil)/TU) == 7))
       Serial.print(' ');
    
    spaceMil = 0;
  }
  else if (currentState == !DATA_LEVEL and prev == DATA_LEVEL)
  {
    spaceMil = millis();
    timings[current] = int(round((millis()+100-letterMil)/TU));
    current++;
  }
 
  if (current !=0 and (millis()-spaceMil)>= 2800 and spaceMil !=0)
    process_letter();
 
  
  prev = currentState;
  
  
  
}
