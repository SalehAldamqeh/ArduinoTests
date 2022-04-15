#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
}
int temp;
long Pressure;
void loop() {
  if (HC12.available()) {  
    // If HC-12 has data
    byte buff[6];
    HC12.readBytes(buff,6);
    temp=((buff[0]<<8)+(buff[1]));
    Pressure=(((buff[2]<<8)+(buff[3]))*65536)+((buff[4]<<8)+(buff[5]));
    Serial.print("Temperature= ");
    Serial.println(temp);
    Serial.print("Pressure= ");
    Serial.println(Pressure);
    Serial.println();
  }
}
