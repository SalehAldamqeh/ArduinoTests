#include "TM1637.h"
#define lb  9
#define rb  11
#define r   13
#define g   12
#define go  10
#define di0 3
#define clk 2

TM1637 dis(clk,di0);

int a[]={2, 3, 2, 3, 2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

void setup() {
  // put your setup code here, to run once:
  pinMode(go,INPUT_PULLUP);
  pinMode(lb,INPUT_PULLUP);
  pinMode(rb,INPUT_PULLUP);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  Serial.begin(9600);
  dis.set(BRIGHT_TYPICAL);
  dis.init();
  
  digitalWrite(r,1);
  digitalWrite(g,1);
  dis.displayStr("STRT");
  delay(1000);
  digitalWrite(r,0);
  digitalWrite(g,0);
  dis.clearDisplay();

  

  
}
int x=0,xQ=0,head=0,headQ=0;
int q[]=  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int q2[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
bool Chosen=true,ChosenQ=true;
void loop() {

  // put your main code here, to run repeatedly:
  if(!digitalRead(go)){

    if(head>=sizeof(q)/2){
      dis.displayStr("REST");
      Serial.println("reset");
      for(int i=0;i<sizeof(q)/2;i++)
        q[i]=0;
      head=0;

      Serial.print("{");
      Serial.print(q[0]);
      for(int i=1;i<sizeof(q)/2;i++){
        Serial.print(", ");
        Serial.print(q[i]);
      }
      Serial.println("}");
    }

    if(headQ>=sizeof(q2)/2){
      Serial.println("reset");
      for(int i=0;i<sizeof(q2)/2;i++)
        q2[i]=0;
      headQ=0;

      Serial.print("{");
      Serial.print(q2[0]);
      for(int i=1;i<sizeof(q2)/2;i++){
        Serial.print(", ");
        Serial.print(q2[i]);
      }
      Serial.println("}");
      digitalWrite(r,1);
      digitalWrite(g,1);
      delay(1000);
      digitalWrite(r,0);
      digitalWrite(g,0);
    }
    
    digitalWrite(g,0);
    digitalWrite(r,0);
    
    for(int i=0;i<random(100);i++){
      dis.display(3,i%10);
      dis.display(2,i%10);
      dis.display(1,i%10);
      dis.display(0,i%10);
      delay(50);
    }
      dis.clearDisplay();
    while(Chosen){
      x=random(1,sizeof(q)/2+1);
      bool tmp=true;
      for(int i=0;i<sizeof(q)/2;i++){
        if(q[i]==x){
          Chosen=true;
          break;
        }
        if(i==sizeof(q)/2-1)
        Chosen=false;
      }
    }
    Chosen=true;
    q[head++]=x;
    Serial.print("{");
    Serial.print(q[0]);
    for(int i=1;i<sizeof(q)/2;i++){
      Serial.print(", ");
      Serial.print(q[i]);
    }
    Serial.println("}");

    Serial.println(x);

    

    while(ChosenQ){
      xQ=random(1,sizeof(a)/2+1);
      bool tmp=true;
      for(int i=0;i<sizeof(q2)/2;i++){
        if(q2[i]==xQ){
          ChosenQ=true;
          break;
        }
        if(i==sizeof(q2)/2-1)
        ChosenQ=false;
      }
    }
    ChosenQ=true;
    q2[headQ++]=xQ;
    Serial.print("{");
    Serial.print(q2[0]);
    for(int i=1;i<sizeof(q2)/2;i++){
      Serial.print(", ");
      Serial.print(q2[i]);
    }
    Serial.println("}");

    Serial.println(xQ);

    

    
    dis.display(3,xQ%10);
    dis.display(2,xQ/10);
    dis.display(1,x%10);
    dis.display(0,x/10);

    while(!digitalRead(go))
      delay(10);

    while(!digitalRead(go)){
      delay(1);
    }
    if(a[xQ-1]==3){
       digitalWrite(g,1);
       digitalWrite(r,1);
       while(digitalRead(go)){
        delay(100);
       }
    }
    else{
    while(true){
      byte answer=!digitalRead(lb)<<1|!digitalRead(rb);
      if(answer!=0){
        if(answer==a[xQ-1])
          digitalWrite(g,1);
        else 
          digitalWrite(r,1);

        break;
      }
    }
    }
    
  }
  
}
