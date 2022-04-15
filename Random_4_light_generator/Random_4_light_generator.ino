void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
    for(int i=6;i<=9;i++,pinMode(i,OUTPUT));
    pinMode(13,INPUT);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
}
int a,preA,c=0;
void loop() {
  // put your main code here, to run repeatedly:
  a=digitalRead(13);
  if(a==1&&preA==0){
    int b=random(1,5);
    if(b==1){
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
    }
    else if(b==2){
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
    }
    else if(b==3){
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
    }
    else if(b==4){
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
    }
    Serial.println(b);
    preA=1;
    c=0;
    }
  else if(a==0&&preA==1){
    preA=0;
  }
  c++;
  if(c==10000){
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    c=0;
  }
  delay(1);
}
