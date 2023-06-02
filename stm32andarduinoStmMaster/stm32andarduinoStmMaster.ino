// code di master è stm32  Funziona provato
#define LED_BUILTIN PC13
#include<Wire.h>// i2c comunication fra stm32 e arduino static
 String CombineStr ="";
//unsigned int k =0; //Master The Basics Of Arduino - Full Arduino Programming Course
//char Receive ;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
Wire.begin(); // non dare indrizzo significa che è master 
Serial.begin(9600);
}
void loop()
{Wire.requestFrom(3,7);// 3=indrizzo di device , $ numero di bit che deve 
// inviare il slave. 
Serial.print("l'altro ha scritto ,,,");
while(Wire.available())
{
char a =Wire.read();
CombineStr +=a;
Serial.println(a);
Serial.println(CombineStr);
if(CombineStr == "vediamo")
  {  
   Serial.print("dentro oop xk è ");
   Serial.println(CombineStr);
   digitalWrite(LED_BUILTIN, HIGH); 
   delay(800);                       // wait for a second
   digitalWrite(LED_BUILTIN, LOW); 
   CombineStr ="";
  }
delay(1000);
}
}
