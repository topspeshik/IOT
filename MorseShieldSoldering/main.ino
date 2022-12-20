#define dataPin 3 // пин подключен к входу DS
#define latchPin 4 // пин подключен к входу ST_CP
#define clockPin 5 // пин подключен к входу SH_CP
#define led 2

void setup() {
    Serial.begin(9600);
    // устанавливаем режим работы пинов OUTPUT
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    // ставим HIGH на "защёлку", чтобы регистр не принимал сигнал
    digitalWrite(latchPin, HIGH);
    digitalWrite(led, HIGH);

}

void loop() {

    digitalWrite(latchPin, LOW); // цифра 5
    shiftOut(dataPin, clockPin, LSBFIRST, 0b10110110);
    Serial.println( );
    digitalWrite(latchPin, HIGH);
    delay(1000);

}
