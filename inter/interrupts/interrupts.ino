#define btn_pin 2
#define led_pin 13

bool state = LOW;

void setup() {
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  int int_number = digitalPinToInterrupt(btn_pin);
  attachInterrupt(int_number, _blink, RISING);
  
  
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B = TCCR1B | (1 << CS12);
  TIMSK1 = TIMSK1 | (1 << TOIE1);
  pinMode(LED_BUILTIN, OUTPUT);
  sei();
}

void loop() {
  digitalWrite(led_pin, state);
    delay(50);
}

void _blink() {
  state = !state;
}

ISR(TIMER1_OVF_vect) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
