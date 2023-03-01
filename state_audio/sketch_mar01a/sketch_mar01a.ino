#define door_pin 10

bool unlocked = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(door_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  update_state();
  do_action();
}

void update_state(){
  bool coin = get_coin();
  bool push = get_push();
  if (coin){
    unlocked = true;
  }
  if (push){
    unlocked = false;
  }
}

void do_action(){
  if (unlocked){
    digitalWrite(door_pin, HIGH);
  } else {
    digitalWrite(door_pin, low);
  }
}
