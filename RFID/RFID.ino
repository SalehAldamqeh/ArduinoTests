
//AHA
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 8
MFRC522 mfrc522(SS_PIN, RST_PIN);
byte card_ID[4];

byte First_card_ID[4]={0xf6,0xeb,0xd4,0xab};

boolean State=false;
int RedLed=6;
int GreenLed=5;
int Buzzer=7;
void setup() {
  
  Serial.begin(9600); 
 SPI.begin();  
 mfrc522.PCD_Init(); 
 Serial.println("Ready to Read a Card ");
for(int def=5;def<8;def++){
 pinMode(def,OUTPUT); 
}

}

void cmp_id(){
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if(card_ID[i]==First_card_ID[i]){
     State=true; 
  }
  else{
     State=false; 
     i=5;
  }
  }
}

void loop() {

   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;
 }

 
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;
 }
  
  Serial.print("Card Number UID:");
  digitalWrite(Buzzer,HIGH);
 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID[i]=mfrc522.uid.uidByte[i];
     Serial.print(" - ");
     Serial.print( card_ID[i],HEX);
     Serial.print(" - ");
   
}
Serial.println();

delay(500);

 digitalWrite(Buzzer,LOW);
cmp_id();
if(State==true){ Serial.println("Accepted OK, Valid card"); digitalWrite(GreenLed,HIGH);digitalWrite(RedLed,LOW);  }
if(State==false){Serial.println("Error ! Invalid card");digitalWrite(RedLed,HIGH);digitalWrite(GreenLed,LOW);   }

delay(500);

digitalWrite(GreenLed,LOW);digitalWrite(RedLed,LOW);
}
