void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}
int x=0,y=-1;
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3,x);
  if(x==255||x==0)y=y*-1;
  x+=y;
  Serial.println(x);
  delay(50);
}
