#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6

void setup() {
  Serial.begin(9600);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
}

int p3 = 0;
int p4 = 0;
String buttons; 

void loop() {
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, HIGH);
  p3 = digitalRead(pin3);
  p4 = digitalRead(pin4);
  
  buttons = "";
  
  if (p3 == 0 && p4 == 1)
    buttons += "2";
  else if (p3 == 1 && p4 == 0) 
    buttons += "1";
  else if (p3 == 1 && p4 == 1)
    buttons += "12";
    
  pinMode(pin5, INPUT);
  pinMode(pin6, OUTPUT);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, HIGH);
  
  p3 = digitalRead(pin3);
  p4 = digitalRead(pin4);
  
  if (p3 == 0 && p4 == 1) 
    buttons += "4";
  else if (p3 == 1 && p4 == 0) 
    buttons += "3";
  else if (p3 == 1 && p4 == 1) 
    buttons += "34";
  
  Serial.println(buttons);
}
