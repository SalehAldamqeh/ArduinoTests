#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00002";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
void setup() {
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();          //This sets the module as transmitter
Serial.begin(9600);
}
void loop()
{
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  Serial.println(text);
  delay(1000);
}
