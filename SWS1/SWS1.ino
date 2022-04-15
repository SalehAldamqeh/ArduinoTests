#include <SoftwareSerial.h>
SoftwareSerial SWS1(10,9);
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   SWS1.begin(9600);
}
int temp=-50,pres=18038;
void loop() {
  // put your main code here, to run repeatedly:
  byte buff[]={(byte)(temp+50),(byte)(pres>>8),(byte)(pres)};
  SWS1.write(buff,3);
  delay(500);
}
