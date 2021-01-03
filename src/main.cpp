
#define F_CPU 1000000UL 

#include <SPI.h>
#include <avr/io.h>
#include <util/delay.h>
#include <Canbus.h>
char UserInput;
int data;
char buffer[456];  //Data will be temporarily stored to this buffer before being written to the file




void setup() {
Serial.begin(115200);
Serial.println("CAN-Bus Demo");

if(Canbus.init(CANSPEED_500))  /* Initialise MCP2515 CAN controller at the specified speed */
  {
    Serial.println("CAN Init ok");
  } else
  {
    Serial.println("Can't init CAN");
  } 
   
  delay(1000); 
}

void loop() {
  Canbus.message_rx(buffer);
}