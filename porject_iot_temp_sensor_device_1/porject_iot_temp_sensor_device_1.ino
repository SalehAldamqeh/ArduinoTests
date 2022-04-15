#include <TroykaDHT.h>

DHT dht(3,DHT11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int t=0,h=0;
void loop() {
  // put your main code here, to run repeatedly:
  dht.read();
  t=(int)dht.getTemperatureC();
  h=(int)dht.getHumidity();
  Serial.println(t);
  Serial.println(h);
  delay(1000);
}
