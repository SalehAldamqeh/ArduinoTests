int state=false;
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),blink,CHANGE);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void blink(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //Serial.println((int)interrupt_time+"\t"+(int)last_interrupt_time);
  if (interrupt_time - last_interrupt_time > 200)
 {
   state=!state;
  Serial.println(state);
 }
 last_interrupt_time = interrupt_time;
  digitalWrite(4,state);
}
void sevenSig(int x){
  switch (x){
  case 1:{  }

  }
}
