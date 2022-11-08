#define ledPin 11

bool ledPos = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  cli();
  EICRA = 0;
  EICRA = EICRA | (1 << ISC11);
  EICRA = EICRA | (1 << ISC10);
  EIMSK = EIMSK | (1 << INT1);
  sei();
}

ISR(INT1_vect){ 
  ledPos = !ledPos;
}

void loop() {
  digitalWrite(ledPin, ledPos);
}

