#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);
const byte address[6] = "00001";
int t=0,h=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available()) {
    char buff[32] = "";
    radio.read(&buff, sizeof(buff));
    t=buff[0];
    h=buff[1];
    Serial.println(t);
    Serial.println(h);
  }
}
