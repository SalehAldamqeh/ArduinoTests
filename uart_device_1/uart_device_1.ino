#define r A6
#define b A7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(r,OUTPUT);
  pinMode(b,OUTPUT);
  digitalWrite(r,1);
  digitalWrite(b,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read()==0){
    digitalWrite(r,1);
    digitalWrite(b,0);
  }
  else{
     digitalWrite(r,1);
     digitalWrite(b,0);
  }
}
