
// These are the pins for the shield!
#define _yp 27  // must be an analog pin, use "An" notation!
#define _xm 14  // must be an analog pin, use "An" notation!
#define _ym 4   // can be a digital pin
#define _xp 16   // can be a digital pin

#define MINPRESSURE 10
#define MAXPRESSURE 1000




  
//   uint8_t i, valid=1; 
//  
//#define NUMSAMPLES 2
//int samples[NUMSAMPLES];
//# if (NUMSAMPLES >= 2)
//static void insert_sort(int array[], uint8_t size) {
//  uint8_t j;
//  int save;
//  
//  for (i = 1; i < size; i++) {
//    save = array[i];
//    for (j = i; j >= 1 && save < array[j - 1]; j--)
//      array[j] = array[j - 1];
//    array[j] = save; 
//  }
//}
//
//#endif

/*  uint8_t xp_port = digitalPinToPort(_xp);
  uint8_t yp_port = digitalPinToPort(_yp);
  uint8_t xm_port = digitalPinToPort(_xm);
  uint8_t ym_port = digitalPinToPort(_ym);

  uint8_t xp_pin = digitalPinToBitMask(_xp);
  uint8_t yp_pin = digitalPinToBitMask(_yp);
  uint8_t xm_pin = digitalPinToBitMask(_xm);
  uint8_t ym_pin = digitalPinToBitMask(_ym);*/



int readTouchX(void) 
{ static int x=0;
  pinMode(_yp, INPUT);
  pinMode(_ym, INPUT);
digitalWrite(_yp, LOW);
digitalWrite(_ym, LOW);
   
  pinMode(_xp, OUTPUT);
  pinMode(_xm, OUTPUT);
  //
digitalWrite(_xp, HIGH);
digitalWrite(_xm, LOW);
// 
//   for (i=0; i<NUMSAMPLES; i++) {
//     samples[i] = analogRead(_yp);
//   }
//#if NUMSAMPLES > 2
//   insert_sort(samples, NUMSAMPLES);
//#endif
////#if NUMSAMPLES == 2
//   //if (samples[0] != samples[1]) { valid = 0; }
////#endif
//   x = (1023-analogRead(_yp));
//return  x;
//
//x=analogRead(_yp);
//if (x>2) {
//
//
//Serial.print("X read xm= "); Serial.print(x);

    
   return  (1023-analogRead(_yp));
//   }
//
//else {
//     return  0;
//   }
}

   
int readTouchY(void) { int y=0;
   pinMode(_xp, INPUT);// è cambiato da get x
   pinMode(_xm, INPUT);// è cambiato da get  x
  // *portOutputRegister(xp_port) &= ~xp_pin;
digitalWrite(_xp, LOW);
digitalWrite(_xm, LOW); 
   pinMode(_yp, OUTPUT);// è cambiato da
   //   *portOutputRegister(yp_port) |= yp_pin;
digitalWrite(_yp, HIGH);
   pinMode(_ym, OUTPUT);// è cambiato da
digitalWrite(_ym, LOW); 
//   for (int i=0; i<NUMSAMPLES; i++) {
//     samples[i] = analogRead(_xm);
//   }
//#if NUMSAMPLES > 2
//   insert_sort(samples, NUMSAMPLES);
//#endif
//#if NUMSAMPLES == 2
//   if (samples[0] != samples[1]) { valid = 0; }
//#endif
//  y=analogRead(_xm);
//  if (y>2) {
//  
//  
//  //Serial.print("\t Y read ym= "); Serial.print(y);

    
   return  (1023-analogRead(_xm));
//   }
//    else {
//     return  0;
//   }
}
   
//
int get_pressure(int e)
 {// Set X+ to ground
  static  int z=0;
  int _rxplate= 300;
   pinMode(_xp, OUTPUT);
  // *portOutputRegister(xp_port) &= ~xp_pin;
   digitalWrite(_xp, LOW); 
   // Set Y- to VCC
  //   *portOutputRegister(ym_port) |= ym_pin;
   //  ym è gia in out mode da get y 
   pinMode(_ym, OUTPUT);
   digitalWrite(_ym, HIGH); 
    // Hi-Z X- and Y+
   // *portOutputRegister(yp_port) &= ~yp_pin;
   //   xm è gia basso   e input mode  da get y 
   pinMode(_xm, INPUT);// è cambiato da get  x
  // *portOutputRegister(xp_port) &= ~xp_pin;
   digitalWrite(_xm, LOW);
   pinMode(_yp, INPUT);
   digitalWrite(_yp, LOW);  
   int z1 = analogRead(_xm); 
   int z2 = analogRead(_yp);
   if (_rxplate != 0) {
     // now read the x 
     float rtouch;
     rtouch = z2;
     rtouch /= z1;
     rtouch -= 1;
     rtouch *= e;
     rtouch *= _rxplate;
//      Serial.print("ZZX prima  = ");
//   Serial.println(rtouch);
     rtouch /= 1024;  
     z = rtouch; }  
//   else {
//     z = (1023-(z2-z1));
//   }
//
//  Serial.print("ZZX  dopo= ");
//   Serial.println(z);
//   if (! valid) {
//     z = 0;
//   }
   return  z;
}

 


 class Tspoint { 
  public:
  
int xi;
int yi;
int zi;
} ;







// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
 Tspoint pxyz ;

void setup(void) {
  Serial.begin(4800);
}

void loop(void) {
  // a point object holds x y and z coordinates
 
  pxyz.xi=readTouchX();
  pxyz.yi=readTouchY();
  pxyz.zi=get_pressure(pxyz.xi);
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
 // if ( pxyz.zi > MINPRESSURE &&  pxyz.zi < MAXPRESSURE) {
     Serial.print("X = "); Serial.print(pxyz.xi);
     Serial.print("\tY = "); Serial.print(pxyz.yi);
     Serial.print("\tPressure = "); Serial.println( pxyz.zi);
  }
