#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SoftwareSerial.h>
#define seaLevelPressure_hPa 1013.25
Adafruit_BMP085 bmp;
  int temp;  
  long Pressure;
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  while (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    delay(500);
    }
  }
}
void loop() {
  
//-----------------------------------
    Serial.print("Temperature = ");
    temp=bmp.readTemperature();
    Serial.print(temp);
    Serial.println(" *C");   
            
    Serial.print("Pressure = ");
    Pressure=bmp.readPressure();
    Serial.print(Pressure);
    Serial.println(" Pa");
//----------------------------------
    byte buff[]={(byte)(temp>>8),(byte)(temp),(byte)(Pressure>>24),(byte)(Pressure>>16),(byte)(Pressure>>8),(byte)(Pressure)};
    HC12.write(buff,6);
    Serial.println();
     delay(500);
}

    
      
    
    
   
