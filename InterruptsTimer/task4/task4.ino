#define sensor_pin A0

bool reading = false;
long time = 0;

void setup() {
  Serial.begin(9600);

  cli();

  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 3900;

  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);

  pinMode(sensor_pin, INPUT);

  sei();
}

ISR(TIMER1_COMPA_vect) { reading = true; }

void loop() {
  if (reading) {
    int data = analogRead(A0);

    Serial.println(millis() - time);
    Serial.println(data);
    Serial.println();

    time = millis();
    reading = false;
  }
}