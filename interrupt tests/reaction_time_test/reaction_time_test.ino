/*
 * Without Serial connection
 * interrupt took about 9us to take place
 * pulling took about 5us to take place (Note: the code dose not do anythin but pulling)
 * 
 * With Serial connection (115200 pbs)and without printing
 * interrupt took about 10.5us to take place
 * pulling took about 4.5us to take place (Note: the code dose not do anythin but pulling)
 * 
 * 
 * With Serial connection (115200 pbs)and with printing
 * interrupt took about 11.5us to take place
 * pulling took about 74.4us to take place 
 * 
 */
void int_ISR(){
  if(digitalRead(2))
    digitalWrite(3, 1);
  else
    digitalWrite(3, 0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(115200);
  //attachInterrupt(digitalPinToInterrupt(2), int_ISR, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, digitalRead(2));
  Serial.print(digitalRead(2));
}
