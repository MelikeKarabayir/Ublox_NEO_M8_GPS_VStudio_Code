//Kütüphane Tanımlamaları
#include <TinyGPS++.h>
#include "gps_deneme.h"
//Sensör sabitleri
unsigned long simdiki_zaman = 0;
unsigned long onceki_zaman = 0;
unsigned long aralik = 500;
static const uint32_t GPSBaud = 9600;

//SerialEvent
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;

void setup()
{
  Serial.begin(115200);
	Serial3.begin(GPSBaud);
  inputString.reserve(200);
	Serial.println(F("GPS Verileri Aliniyor.."));
}
void loop()
{ 
  simdiki_zaman = millis();
  if (simdiki_zaman - onceki_zaman >= aralik)
  {
    
    if (stringComplete)
    {
      Serial.print("hiğ3");
      Serial.println(inputString);
      // clear the string:
      inputString = "";
      stringComplete = false;


    }
   //BFC_GPS_Loop();
   
   onceki_zaman = simdiki_zaman;
  }
}

void serialEvent() {
    while(1)
    {
    Serial.print("hiğ");
    // get the new byte:
    BFC_GPS_Loop();
    double inChar = latitude;
    Serial.print(inChar);
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    Serial.print(inputString);
    if (inChar == '\n') {
      Serial.print("hiğ1");
      stringComplete = true;
    }
    }
  
}
