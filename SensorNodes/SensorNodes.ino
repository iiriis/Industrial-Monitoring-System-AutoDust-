#include <SPI.h>
#include <LoRa.h>

char *p;

void setup() {
  DDRB|=0x2F;
  DDRD|=0x1C;
  PORTB&=0xD0;

  if (!LoRa.begin(915E6)) {
     PORTB|=0x20;
     while(1);
  }

}


void loop() {

  uint8_t add=0x00;

  PORTB=add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);  
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  p = "df,"+analogRead(A0);
  sendPacket(p);
  p = "l1,"+analogRead(A3);
  sendPacket(p);
  p = "l2,"+analogRead(A4);
  sendPacket(p);
  p = "l3,"+analogRead(A5);
  sendPacket(p);
  p = "l4,"+analogRead(A6);
  sendPacket(p);
  p = "l5,"+analogRead(A7);
  sendPacket(p);
  PORTD|=0x00;
  p = "D0,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x20;
  p = "D1,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x40;
  p = "D2,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x60;
  p = "D3,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x80;
  p = "D4,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0xA0;
  p = "D5,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0xC0;
  p = "D6,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0xE0;
  p = "D7,"+digitalRead(A2);
  sendPacket(p);


String s="";

  LoRa_rxMode();
  while (LoRa.available()) {
      s+=(char)LoRa.read();
    }

    if(s.equals("Repeat"))   
    {
      LoRa_txMode();
      readData();
    }


    
    
      
}


void readData()
{
  uint8_t add=0x00;
  
  PORTB=add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);  
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  PORTB=++add;
  p = add+","+analogRead(A1);
  sendPacket(p);
  p = "df,"+analogRead(A0);
  sendPacket(p);
  p = "l1,"+analogRead(A3);
  sendPacket(p);
  p = "l2,"+analogRead(A4);
  sendPacket(p);
  p = "l3,"+analogRead(A5);
  sendPacket(p);
  p = "l4,"+analogRead(A6);
  sendPacket(p);
  p = "l5,"+analogRead(A7);
  sendPacket(p);
  PORTD|=0x00;
  p = "D0,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x20;
  p = "D1,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x40;
  p = "D2,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x60;
  p = "D3,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0x80;
  p = "D4,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0xA0;
  p = "D5,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0xC0;
  p = "D6,"+digitalRead(A2);
  sendPacket(p);
  PORTD|=0xE0;
  p = "D7,"+digitalRead(A2);
  sendPacket(p);

}


void LoRa_txMode(){
  LoRa.idle();                          
  LoRa.enableInvertIQ();                
}


void LoRa_rxMode(){
  LoRa.disableInvertIQ();               
  LoRa.receive();                       
}



void sendPacket(char *data)
{
 LoRa.beginPacket();
 LoRa.print(data);
 LoRa.endPacket();
}



