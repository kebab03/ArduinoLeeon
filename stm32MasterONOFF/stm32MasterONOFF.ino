//I2C Master Code (STM32F103C8)
//I2C Communication between STM32 and Arduino
//Circuit Digest    
//  funziona  ok provato  
//https://circuitdigest.com/microcontroller-projects/stm32-stm32f103c8-i2c-communication-tutorial

#include<Wire.h>                      
#include<SoftWire.h>                   //Library for I2C Communication functions

#define LED PC13
//#define buttonpin PA0

void setup() 
{ 
  
  Serial.begin(9600);                  //Begins Serial Communication at 9600 baud rate
  //pinMode(buttonpin,INPUT);            //Sets pin PA0 as input 
  pinMode(LED,OUTPUT);                 //Sets PA1 as Output
  Wire.begin();                        //Begins I2C communication at pin (B6,B7)
}

void loop()
{  Wire.requestFrom(8,1);               // request  bytes from slave arduino(8)
    byte a = Wire.read();                // receive a byte from the slave arduino and store in variable a 
    if (a==0)  {                          //ho messo 0  invece di 1 Logic to turn Master LED ON (if received value is 1) or OFF (if received value is 0){ 
      digitalWrite(LED,HIGH);
      Serial.println("Master LED ON");  }
    else {
      digitalWrite(LED,LOW);
      Serial.println("Master LED OFF"); }
   /*int pinvalue = digitalRead(buttonpin);    //Reads the status of the pin PA0
  if(pinvalue==HIGH)                         //Logic for Setting x value (To be sent to slave Arduino) depending upon inuput from pin PA0
    {
      x=1;
    }
    
  else
   {
      x=0;
   }
  */
int incomingByte = 0; // for incoming serial data
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

     Serial.println();
  } 
  Wire.beginTransmission(8);                 // starts transmit to device (8-Slave Arduino Address)
  Wire.write(1);                             // sends the value x to Slave
  Wire.endTransmission();                    // stop transmitting
  delay(500);
  }
   
