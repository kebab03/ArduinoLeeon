#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <TouchScreen.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define YP A2
#define XM A3
#define YM 8
#define XP 9

#define TS_MINX 920
#define TS_MINY 120
#define TS_MAXX 150
#define TS_MAXY 940

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define BOXSIZE 40
#define PENRADIUS 3

#define MINPRESSURE 10
#define MAXPRESSURE 2000
void setup(void) {
 Serial.begin(9600);

 tft.reset();
  tft.begin(0x9341);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.fillScreen(BLACK);
  
  
  tft.fillRect(0, 0, 120, 120, GREEN);
  tft.fillRect(120, 0, 120, 120, RED);
  tft.setCursor(15, 45);
  tft.println("M1 ON");
  tft.setCursor(128, 45);
  tft.println("M1 OFF");


}
void loop(void) {
  
  


  
 TSPoint p = ts.getPoint();
 if (p.z > ts.pressureThreshhold) {
    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
 }
 delay(100);
} 
