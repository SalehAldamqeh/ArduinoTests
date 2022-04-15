int CLK=4,DIO=3;
#include <TM1637Display.h>
TM1637Display display(CLK, DIO);
void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(OUTPUT,11);
  pinMode(OUTPUT,6);
  pinMode(OUTPUT,3);
  Serial.begin(9600);
  display.setBrightness(7);
}
int x=0;
int y=0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(2));
  Serial.print(digitalRead(7));
  Serial.println(digitalRead(12));
  
  for(int i=0;i<300;i++){
  if(!digitalRead(2)){
  y=y+100;
  i=0;
  }
  if(y==1300){
    x=y=0;
  }
  if(!digitalRead(7)){
  x++;
  i=0;
  }
  if(!digitalRead(12)){
  x=0;
  i=0;
  }
  Serial.print(digitalRead(2));
  Serial.print(digitalRead(7));
  Serial.println(digitalRead(12));
  display.showNumberDec(y +x,false,4,0);
  delay(200);
  }
  x++;
   if(x==60){
    y=y+100;
    x=0;
  }
  /*if(y==1300){
    x=y=0;
  }*/
  
  
}
