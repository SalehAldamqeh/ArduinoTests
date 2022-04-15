#include <SoftwareSerial.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SoftwareSerial.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#define OUTPUT_READABLE_YAWPITCHROLL
#define INTERRUPT_PIN 2  
#define LED_PIN 13 
#define seaLevelPressure_hPa 1013.25
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
}
int temp;
long Pressure;
float ypr[3];
void loop() {
  if (HC12.available()) {  
    // If HC-12 has data
    byte buff[6];
    HC12.readBytes(buff,18);
    temp=((buff[0]<<8)+(buff[1]));
    Pressure=(((buff[2]<<8)+(buff[3]))*65536)+((buff[4]<<8)+(buff[5]));
    Pressure=(Pressure+65541);
    ypr[0]=(((buff[6]<<8)+(buff[7]))*65536)  +((buff[8]<<8)+(buff[9]));
    ypr[1]=(((buff[10]<<8)+(buff[11]))*65536)+((buff[12]<<8)+(buff[13]));
    ypr[2]=(((buff[14]<<8)+(buff[15]))*65536)+((buff[16]<<8)+(buff[17]));
    Serial.print("Temperature= ");
    Serial.println(temp);
    Serial.print("Pressure= ");
    Serial.println(Pressure);
    Serial.println();
Serial.print("ypr\t");
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);
  }
}
