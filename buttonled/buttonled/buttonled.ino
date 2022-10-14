#define btn_pin 3
#define led_pin 10
#define check_time 20
long int count = 0;
bool click = false;
int a = 255;

void setup() {
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(btn_pin);
  
  if (val == 0){
    for (int i = 0; i < check_time - 1; i++){
      val = digitalRead(btn_pin);
      if (val == 0){
        count++;
      }
      if(val == 1){   
        count--;
      }
      
    }
  }

  if (count >= 19 and a > 0){
    click = !click;
    analogWrite(led_pin, a);
    a = a - 1;

    
    Serial.println(count);

  }
  if(val == 1){
    digitalWrite(led_pin, !click);
  count = 0;
  a = 255;
  }
}
