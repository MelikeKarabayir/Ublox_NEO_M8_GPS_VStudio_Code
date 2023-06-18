//SENSOR SABITLERI

double latitude,longitude;
uint16_t year;
uint8_t month, day, hour, minute, second;
//ADRES TANIMLAMA

//KÜTÜPHANENİN KULLANILACAĞI DEĞİŞKEN TANIMLAMA
TinyGPSPlus gps;

void BFC_GPS_Loop(void)
{   
while (Serial3.available() > 0)
    if (gps.encode(Serial3.read()))
      

      Serial.print(F("KONUM BİLGİSİ :   "));
  if (gps.location.isValid()) {

	latitude =  gps.location.lat();
	longitude = gps.location.lng();
	Serial.print("ENLEM:");
  Serial.print(latitude, 6);
  Serial.print(F(","));
	Serial.print("BOYLAM:");
  Serial.print(longitude, 6);



  } else {
    Serial.print(F("BULUNMADI!"));
  }
  Serial.print(F("  TARIH / ZAMAN : "));
  if (gps.date.isValid()) {

	year = gps.date.year();
	month = gps.date.month();
	day = gps.date.day();

    Serial.print(day);
    Serial.print(F("/"));
    Serial.print(month);
    Serial.print(F("/"));
    Serial.print(year);
	Serial.print("&&&");

	hour = gps.time.hour();
	minute = gps.time.minute();
	second = gps.time.second();
	
	Serial.print(hour);
    Serial.print(F(":"));
    Serial.print(minute);
    Serial.print(F(":"));
    Serial.print(second);

  } else {
    Serial.print(F("BULUNAMADI!"));
  }
  Serial.println();
  
 
	
}
