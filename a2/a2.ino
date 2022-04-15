int x=A7;
int a0=A4,a1=A3,a2=4,a3=3,a4=2,a5=A5,a6=12;
int b0=A0,b1=9,b2=11,b3=8,b4=6,b5=A1,b6=A2;
void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT,A7);
  pinMode(OUTPUT,a0);
  pinMode(OUTPUT,a1);
  pinMode(OUTPUT,a2);
  pinMode(OUTPUT,a3);
  pinMode(OUTPUT,a4);
  pinMode(OUTPUT,a5);
  pinMode(OUTPUT,a6);
  pinMode(OUTPUT,b0);
  pinMode(OUTPUT,b1);
  pinMode(OUTPUT,b2);
  pinMode(OUTPUT,b3);
  pinMode(OUTPUT,b4);
  pinMode(OUTPUT,b5);
  pinMode(OUTPUT,b6);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int x=(int)(analogRead(x)/10.24);
  Serial.println(x);
  sevenSeg(x);
  delay(100);
}
void sevenSeg(int x){
  int xa=x/10,xb=x%10;
  digitalWrite(a0,!(xa==1||xa==4));
  digitalWrite(a1,!(xa==5||xa==6));
  digitalWrite(a2,!(xa==2));
  digitalWrite(a3,!(xa==1||xa==4||xa==7));
  digitalWrite(a4,(xa==0||xa==2||xa==6||xa==8));
  digitalWrite(a5,!(xa==1||xa==2||xa==3||xa==7));
  digitalWrite(a6,!(xa==0||xa==1||xa==7));
  
  digitalWrite(b0,!(xb==1||xb==4));
  digitalWrite(b1,!(xb==5||xb==6));
  digitalWrite(b2,!(xb==2));
  digitalWrite(b3,!(xb==1||xb==4||xb==7));
  digitalWrite(b4,(xb==0||xb==2||xb==6||xb==8));
  digitalWrite(b5,!(xb==1||xb==2||xb==3||xb==7));
  digitalWrite(b6,!(xb==0||xb==1||xb==7));
}
