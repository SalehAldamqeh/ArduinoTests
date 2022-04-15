/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SoftwareSerial.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
char resR='a';
bool t=0;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(2,INPUT_PULLUP);
}
int lastX=0;
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    int x=((int)text[1]<<8)+(int)text[0];
    Serial.println(x);
    if(x!=lastX+1||x==lastX){
      Serial.println("ERRRRRRRRRRRRRRRRRRRRRRRRROOOOOOOOOOOOOOOOOOOOORRRRRRRRRR");
    }
    lastX=x;
  }
 
}
