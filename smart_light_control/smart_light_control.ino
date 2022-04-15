void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}
bool x=0;
void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(2)){
    digitalWrite(4,x);
    analogWrite(3,8*(x=!x));
    Serial.println(x);
    while(!digitalRead(2)){
      delay(50);
    }
  }
  
}
