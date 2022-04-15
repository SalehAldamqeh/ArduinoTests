#define idle 0
#define flame 1
#define smoke 2
#define flameSensorPin A0
#define alarmPin0 4
#define reset 5
bool alarmState=false;
int state=idle;
void setup() {
  // put your setup code here, to run once:
  pinMode(flameSensorPin,INPUT);
  pinMode(alarmPin0,OUTPUT);
  pinMode(reset,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int flameSensor=analogRead(A0);
  Serial.print(state);
  Serial.println(flameSensor);
  switch (state){
  case idle:if(flameSensor<=200)state=flame;
  break;
  case flame:if(!digitalRead(reset))state=idle;digitalWrite(alarmPin0,alarmState);alarmState=!alarmState;
  break;
  case smoke:state=idle;
  break;
  }
 // delay(500);
}
