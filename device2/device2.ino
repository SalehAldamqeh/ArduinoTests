int sev[7]={4,5,6,7,8,9,10};
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  for(int j=0;j<7;pinMode(sev[j++],OUTPUT));
  attachInterrupt(digitalPinToInterrupt(2),faster,RISING);
  attachInterrupt(digitalPinToInterrupt(3),slower,RISING);
  Serial.begin(9600);
}
int i=0,y=80;
void loop() {
  // put your main code here, to run repeatedly:
  seven(i++);
  if(i>9)
    i=0;
  for(int j=0;j<y;j++){delay(1);}
}

int on=true;
void faster(){
  static unsigned long p=0;
  unsigned long c=millis();
  if((c-p)>200){
    if(y>10)
      y/=2;
      Serial.println(y);
  }
  p=c;
}
void slower(){
  static unsigned long p=0;
  unsigned long c=millis();
  if((c-p)>200){
    if(y<20480)
      y*=2;
    Serial.println(y);
  }
  p=c;
}
void seven(int x){
  digitalWrite(sev[0],!(x==1||x==4));
  digitalWrite(sev[1],!(x==5||x==6));
  digitalWrite(sev[2],!(x==2));
  digitalWrite(sev[3],!(x==1||x==4||x==7));
  digitalWrite(sev[4],(x==0||x==2||x==6||x==8));
  digitalWrite(sev[5],!(x==1||x==2||x==3||x==7));
  digitalWrite(sev[6],!(x==0||x==1||x==7));
}
