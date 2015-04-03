/*
  ATmega128RFA1 Dev Board Basic Chat
  by: Jim Lindblom
      SparkFun Electronics
  date: July 3, 2012
  License: Beerware. Feel free to use, reuse, and modify this code
  as you please. If you find it useful, you can buy me a beer.

  This code sets up the ATmega128RFA1's wireless transciever in
  the most basic way possible to serve as a serial gateway.
  Serial into the ATmega128RFA1's UART0 will go out the RF radio.
  Data into the RF radio will go out the MCU's UART0.
*/

#include "RadioFunctions.h"

#define PACK_SIZE 126
char packetBuf[PACK_SIZE];

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(14);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  // Send a message to other RF boards on this channel
  //rfPrint("ATmega128RFA1 Dev Board Online!\r\n");
  
  // Prepare packet
  memset(packetBuf, '*', PACK_SIZE-1);
  packetBuf[PACK_SIZE-1] = '\0';
}

void loop()
{
  
  if (Serial.available())  // If serial comes in...
  {
    Serial.read();
    //rfWrite(Serial.read()); // ...send it out the radio.
    
    // RadioFunctions wants packet as String class... barf
    String packet = String(packetBuf);
    
    unsigned long startTime = millis();
    for (short i = 0; i < 1000; ++i)
    {
      rfPrint(packet);
    }
    unsigned long endTime = millis();
    
    Serial.write("\nTime: ");
    Serial.print(endTime - startTime);//4354
  }
  /*if (rfAvailable())  // If data receievd on radio...
  {
    Serial.print(rfRead());  // ... send it out serial.
  }*/
}
