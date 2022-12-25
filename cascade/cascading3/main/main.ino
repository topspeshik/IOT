
const char lth = 12; //ST_CP to pin 12
const char clk = 13; //SH_CP to pin 13
const char dat = 11; //DS to pin 11

byte bytes[] = {
  B11111100, 
  B01100000,
  B11011010,
  B11110010,
  B01100110,
  B10110110,
  B10111110,
  B11100000,
  B11111110,
  B11110110,
  B00000000};

int count = 0;



void setup() {
  Serial.begin(9600);
  pinMode(lth, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(dat, OUTPUT);
  // Регистр ждет ввод
  digitalWrite(lth, 0);
  shiftOut(dat, clk, LSBFIRST, bytes[10]);
  shiftOut(dat, clk, LSBFIRST, bytes[10]);
  // Больше не ждет
  digitalWrite(lth, 1);
}


void loop() {
 	delay(100);
  count = Serial.available();
  if (count > 0){
    int *numbers = new int[count];
    for(int i = 0; i < count; i++){
      numbers[i] = Serial.read() - '0';
      
    }
  
    Serial.println(numbers[0]);
    if (count == 1){
      digitalWrite(lth, 0);
      shiftOut(dat, clk, LSBFIRST, bytes[numbers[0]]);
      
      digitalWrite(lth, 1);

    }
    else if (count == 2){
      digitalWrite(lth, 0);
      shiftOut(dat, clk, LSBFIRST, bytes[numbers[1]]);
      shiftOut(dat, clk, LSBFIRST, bytes[numbers[0]]);
      digitalWrite(lth, 1);
    }
    
  }
}
