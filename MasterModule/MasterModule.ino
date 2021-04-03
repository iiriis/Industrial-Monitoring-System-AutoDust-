#include <SPI.h>
#include <LoRa.h>
#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);


  if (!LoRa.begin(915E6)) {
    Serial.println("Error!");
    while (1);
  }
}

void loop() {

  int pS = LoRa.parsePacket();
String s="";

   if(!pS)
   {
   LoRa_txMode();
   sendData("Repeat");
   }  


else
{
  LoRa_rxMode();
  
   while (LoRa.available()) 
      s+=(char)LoRa.read();

    Serial.println(s);
  int addrOffset = 0x0000
  byte len = s.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, s[i]);
  }
  
}
    
}
}


void LoRa_txMode(){
  LoRa.idle();                          
  LoRa.enableInvertIQ();                
}


void LoRa_rxMode(){
  LoRa.disableInvertIQ();               
  LoRa.receive();                       
}

void sendData(String message) {
  LoRa.beginPacket();                   
  LoRa.print(message);                  
  LoRa.endPacket(true);                 
}





