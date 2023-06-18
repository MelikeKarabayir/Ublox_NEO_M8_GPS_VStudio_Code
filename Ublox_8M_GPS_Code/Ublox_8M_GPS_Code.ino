//Kütüphane Tanımlamaları
#include <TinyGPS++.h>
#include "BFC_Ublox_8M_GPS.h"
//Sensör sabitleri
unsigned long simdiki_zaman = 0;
unsigned long onceki_zaman = 0;
unsigned long aralik = 500;
static const uint32_t GPSBaud = 9600;

void setup()
{
  Serial.begin(115200);
	Serial3.begin(GPSBaud);
	Serial.println(F("GPS Verileri Aliniyor.."));
}
void loop()
{
  simdiki_zaman = millis();
  if (simdiki_zaman - onceki_zaman >= aralik)
  {
   BFC_GPS_Loop();
   
   onceki_zaman = simdiki_zaman;
  }
}
