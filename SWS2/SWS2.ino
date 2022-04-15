#include <SoftwareSerial.h>
SoftwareSerial SWS2(10,9);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SWS2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte buff[3];
  if(SWS2.available()){
    SWS2.readBytes(buff,3);
    Serial.print("temp: ");
    Serial.println(buff[0]-50);
    Serial.print("press: ");
    Serial.println((buff[1]<<8)+buff[2]);
  }
  else{
    Serial.println("Not Available");
  }
  delay(500);
}
