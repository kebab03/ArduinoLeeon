// Demo based on:
// UTFT_Demo_320x240 by Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
/*

 This sketch uses the GLCD and font 2 only.
 
 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */

#include "SPI.h"

#include "TFT_eSPI.h"

#define TFT_GREY 0x7BEF

TFT_eSPI myGLCD = TFT_eSPI();       // Invoke custom library

unsigned long runTime = 0;
void setup()
{Serial.begin(9600);
  randomSeed(analogRead(A0));
// Setup the LCD
  myGLCD.init();
  myGLCD.setRotation(3);//2 0

  //delay(20);
  Serial.println("setRotation 0:::");
  //myGLCD.setRotation(1);

  delay(20);
 // Serial.print("setRotation 2:::");
 // myGLCD.setRotation(2);
/*
  delay(20);
  Serial.print("setRotation 3:::");
  myGLCD.setRotation(3);*/

}

void loop()
{
  randomSeed(millis());
  //randomSeed(1234); // This ensure test is repeatable with exact same draws each loop
  int buf[318];
  int x, x2;
  int y, y2;
  int r;
  runTime = millis();
// Clear the screen and draw the frame
  myGLCD.fillScreen(TFT_BLACK);
  delay(30);
  Serial.print("Black :::");

  myGLCD.fillRect(0, 0, 319, 14,TFT_RED);
  delay(300);
  Serial.println("TFT_RED :::");
  myGLCD.fillRect(0, 226, 319, 14,TFT_GREY);
delay(350);
  myGLCD.setTextColor(TFT_BLACK,TFT_RED);
  myGLCD.drawCentreString("* TFT_eSPI *", 160, 4, 1);

  delay(400);
  Serial.println("TFT_eSPI :::");
  myGLCD.setTextColor(TFT_YELLOW,TFT_GREY);


  delay(400);
  Serial.println(" arriva Adapted by Bodmer :::");
  myGLCD.drawCentreString("Adapted by Bodmer", 160, 228,1);
  delay(500);
  myGLCD.drawRect(0, 14, 319, 211, TFT_BLUE);
  delay(500);
// Draw crosshairs
  myGLCD.drawLine(159, 15, 159, 224,TFT_RED);
  delay(500);
  myGLCD.drawLine(1, 119, 318, 119,TFT_BLUE);
   delay(500);

  myGLCD.fillScreen(TFT_BLUE);
    delay(40);
  myGLCD.fillRoundRect(80, 70, 239-80,169-70, 3,TFT_RED);
    delay(40);
  myGLCD.setTextColor(TFT_WHITE,TFT_RED);
  myGLCD.drawCentreString("That's it!", 160, 93,2);
  
  delay(200);
  myGLCD.drawCentreString("Restarting in a", 160, 119,2);
    delay(100);
  myGLCD.drawCentreString("few seconds...", 160, 132,2);
  delay(100);
  runTime = millis()-runTime;
  myGLCD.setTextColor(TFT_GREEN,TFT_BLUE);
    delay(400);
  myGLCD.drawCentreString("Runtime: (msecs)", 160, 210,2);
  delay(400);
  myGLCD.setTextDatum(TC_DATUM);
  delay(400);
  myGLCD.drawNumber(runTime, 160, 225,2);
   delay (6000);
   myGLCD.setTextColor(TFT_RED, TFT_BLACK);
   myGLCD.println("Red textfff");///funziona
  delay (2000);
}
