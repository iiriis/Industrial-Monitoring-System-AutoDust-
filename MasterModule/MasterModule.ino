#include <SPI.h>
#include <LoRa.h>

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



