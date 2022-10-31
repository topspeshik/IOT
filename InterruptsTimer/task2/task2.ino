long msCounter = 0;

void setup(){
  Serial.begin(9600);
  cli();
  
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 16000;

  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);

  sei();
}

ISR(TIMER1_COMPA_vect){ msCounter++; }

long myMillis(){ return msCounter; }

void loop(){
  Serial.print("Millis - ");
  Serial.print(millis());
  Serial.print("My millis - ");
  Serial.print(myMillis());
  Serial.println();  
}