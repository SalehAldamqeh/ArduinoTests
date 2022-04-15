int i1=2,i2=A0;
int s1=3,s2=A2;
bool x[]={1,0,0,1,0,1,0,1};
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  digitalWrite(i2,LOW);
  attachInterrupt(digitalPinToInterrupt(i1),sen,RISING);
  Serial.begin(9600);
  digitalWrite(i2,HIGH);
}
int i=0;
void loop() {
  // put your main code here, to run repeatedly:
 
}

void sen(){
  for(int i=0;i<8;i++){
    digitalWrite(s2,x[i]);
    Serial.println("Send: "+x[i]);
  }
  digitalWrite(i2,LOW);
}
