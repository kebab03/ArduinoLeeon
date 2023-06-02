//I2C Slave Code (Arduino)
//I2C Communication between STM32 and Arduino
//Circuit Digest
//  funziona  provato      https://circuitdigest.com/microcontroller-projects/stm32-stm32f103c8-i2c-communication-tutorial
#include<Wire.h>                             //Library for I2C Communication functions

#define LED 13
//#define buttonpin 2

byte x =0;
void setup() 

{
  Serial.begin(9600);                        //Begins Serial Communication at 9600 baud rate
  pinMode(LED,OUTPUT);                       //Sets pin 7 as output
  Wire.begin(8);                             // join i2c bus with its slave Address as 8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);              //Function call when Slave Arduino receives value from master STM32
  Wire.onRequest(requestEvent);              //Function call when Master STM32 request value from Slave Arduino
}

void loop() 
{
  delay(100);
}

void receiveEvent (int howMany)              //This Function is called when Slave Arduino receives value from master STM32
{
  int a = Wire.read();                      //Used to read value received from master STM32 and store in variable a
  
  if (a == 49 | a==10|a==1)                       //   Logic to turn Slave LED ON (if received value is 1) or OFF (if received value is 0)
  {
   digitalWrite(LED,HIGH);
   Serial.println("Slave LED ON");
   Serial.println(a);
   delay(500);
   
  }
  else
  {
    digitalWrite(LED,LOW);
    Serial.println("Slave LED OFF");
    Serial.println(a);
  }
  delay(500);
  
}

void requestEvent()                            //This Function is called when Master STM32 wants value from slave Arduino
{
  //int value = digitalRead(buttonpin);          //Reads the status of the pin 2   
   int value =0;
  if (value == HIGH)                           //Logic to set the value of x to send to master depending upon input at pin 2
  {
    x=1;
  }
  else 
  {
    x=0;
  }
  Wire.write(x);                             // sends one byte of x value to master STM32
}
