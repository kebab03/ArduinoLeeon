//Slave code  arduino 
// #include<SoftWire.h> 
#include<Wire.h>// i2c comunication fra stm32 e arduino 
void setup() {Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin(3);// indrizzo di slave
  // put your setup code here, to run once:
Wire.onRequest(FunzionedaSvogereOnRequest);
}

void loop() {Serial.println("in atesi richiesta");

digitalWrite(LED_BUILTIN, HIGH); 
 delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);  
  // put your main code here, to run repeatedly:

}
void FunzionedaSvogereOnRequest()
{Wire.write("vediamo");
  }
