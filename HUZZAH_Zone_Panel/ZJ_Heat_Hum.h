/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This library is based on the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  These specific functions are related to operatoin of:

   HTU21D-F Humidity & Temp Sensor (HTH)

    HTH VIN -> HFE 3V
    HTH GND -> HFE GND
    HTH SDA -> HFE SDA/4
    HTH SCL -> HFE SCL/5

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.0 - Test/Demo

  +Initialize the HTH
  +Configure basic display
  +Test and demonstrate text refresh at a basic level
  
 ****************************************************/

#include "Adafruit_HTU21DF.h"
//#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
//#define DHTTYPE DHT22
//#define DHTTYPE DHT21

//DHT dht(DHTPIN, DHTTYPE);
Adafruit_HTU21DF htu = Adafruit_HTU21DF();
