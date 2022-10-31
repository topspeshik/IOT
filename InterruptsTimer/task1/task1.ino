#define ledPin 11
bool pos_1 = LOW;
bool pos_2 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  cli();
  TCCR2A = 0;
  TCCR2B = 0;
  TCCR2B = TCCR2B | (1 << CS10);
  TCCR2B = TCCR2B | (1 << CS12);
  TIMSK2 = (1 << TOIE1);
  sei();
}

void loop() {
  digitalWrite(ledPin, pos_1);
  if (pos_1 != pos_2) {
    pos_2 = pos_1;
    Serial.println(millis());
  }
}

ISR(TIMER2_OVF_vect) {
  pos_1 = !pos_1;
}
