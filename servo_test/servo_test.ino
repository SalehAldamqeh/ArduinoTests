#include <dht.h>
#define dht_apin A3
dht DHT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dht_apin);
   Serial.print("Current humidity = ");
   Serial.print(DHT.humidity);
   Serial.print("%  ");
   Serial.print("temperature = ");
   Serial.print(DHT.temperature); 
   Serial.println("C  ");
  delay(5000);
}
