#define ledPin1 3
#define ledPin2 4
#define ledPin3 5

bool pos_1 = false;
bool pos_2 = false;
bool pos_3 = false;

bool blink_2 = false;
bool blink_3 = false;

void setup(){
  Serial.begin(9600);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 62500;
  TCCR1B = TCCR1B | (1 << WGM12);
  TCCR1B = TCCR1B | (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  sei();
}

void loop(){
  digitalWrite(ledPin1, pos_1);
  digitalWrite(ledPin2, pos_2);
  digitalWrite(ledPin3, pos_3);
  if (Serial.available() >= 1){
    int pin = Serial.read();
    if (pin == '2'){
      blink_2 = !blink_2;
    }
    if (pin == '3'){
      blink_3 = !blink_3;
    }
  }
}

ISR(TIMER1_COMPA_vect){
  pos_1 = !pos_1;
  if (blink_2){
    pos_2=!pos_2;
  }
  else{
    pos_2=false;
  }
  if (blink_3){
    pos_3=!pos_3;
  }
  else{
    pos_3=false;
  }
}
