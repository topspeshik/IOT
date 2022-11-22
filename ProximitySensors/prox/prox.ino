const int IRpin = A0;          
int value1; 
#define PIN_TRIG 12
#define PIN_ECHO 11

long duration, cm;
 
void setup() {
  Serial.begin(9600);  
   pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}
 
void loop() {
   //Serial.println(irRead(), DEC);
   float volts = analogRead(IRpin)*0.0048828125;
   float distance=32*pow(volts,-1.10);
   Serial.write(int(distance));
   //Serial.print(" ");
   int numb = hcsr();
   if (numb >= 255){
    numb = 255 ;     
   };
   Serial.write(numb);                    
}

 int  hcsr(){
   digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);

  
  cm = (duration / 2) / 29.1;
delay(250);
  return cm ;
  

 
  
 }

int irRead() {
  int averaging = 0;             
 

  for (int i=0; i<5; i++) {
    value1 = analogRead(IRpin);
    averaging = averaging + value1;
    delay(55);      
  }
  value1 = averaging / 5;    
  return(value1);              
} 
