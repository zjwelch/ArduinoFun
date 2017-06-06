/**************************************************************************

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  These functions are intended for use with HUZZAH FEATHER ESP8266 from adafruit (HFE)
**/

//#include <sstream>

#include <sstream>

#include <SPI.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include "AdafruitIO_WiFi.h"
#include "ZJ_UDPdata.h"
#include "ZJ_Display.h"
#include "ZJ_Heat_Hum.h"


//#include "ILI9341_t3.h"
//#include "Adafruit_HTU21DF.h"
//#include "ZJ_ESP8266.h"

//#include "ZJ_Light.h"
//#include "ZJ_Motion.h"
//#include "ZJ_Sound.h"

#include "secrets.h"

/*String int2str (int i)
{
    ostringstream str;
    str<<i;
    return str.str();
}*/

//Create TFT Screen object
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
//ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);

//Create IO API feed object
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

//Create HTH sensor object
//Adafruit_HTU21DF htu = Adafruit_HTU21DF();

//Initialize the IO feeds
AdafruitIO_Feed *temperature = io.feed("ComputerRoom-Temp01");
AdafruitIO_Feed *humidity = io.feed("ComputerRoom-Humd01");
