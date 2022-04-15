void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
}
int b,w,r,pre,count,count2,preB,preW,preR;
boolean right=false;
void loop() {
  // put your main code here, to run repeatedly:

  b=digitalRead(3);
  w=digitalRead(4);
  r=digitalRead(5);
  Serial.print(b);
  Serial.print(w);
  Serial.print(r);
   Serial.print("\t");
  Serial.print(pre);
  Serial.print("\t");
  Serial.print(right);
  Serial.print("\t");
  Serial.println(count);
  if(pre==0&&b==1&&preB==0){
    pre=1;
    preB=1;
    preW=0;
    preR=0;
    count2++;
  }
  else if(pre==1&&w==1&&preW==0){
    pre=2;
    preB=0;
    preW=1;
    preR=0;
    count2++;
  }
  else if(pre==2&&r==1&&preR==0){
    right=true;
    pre=0;
    preB=0;
    preW=0;
    preR=1;
    count2++;
  }
  else{
    preB=0;
    preW=0;
    preR=0;
    if(b||w||r)
      pre=0;
  }
  if(right){
    digitalWrite(6,HIGH);
    count=0;
    right=false;
  }
  if(count==10){
    digitalWrite(6,LOW);
  }
  count++;
  if(count2==3)
    pre=0;
  delay(100);
}
