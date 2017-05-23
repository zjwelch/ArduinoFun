/**************************************************************************

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: Jeremy Schiefer
  
  These functions are intended for use with HUZZAH FEATHER ESP8266 from adafruit (HFE)


 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.1 - Cleanup

  -After working base demo, cleanup and remove any unneeded references/calls
  -build prototype stubs for project specific functions and classes
  
  vA0.1.0 - Test/Demo

  +Include initial libraries
  +Configure basic constructors for the various devices and sensors

 ***********************************************************************/

//#include <sstream>

#include <sstream>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include "AdafruitIO_WiFi.h"
//#include <Adafruit_GFX.h>
//#include <Adafruit_ILI9341.h>
//#include "ILI9341_t3.h"
//#include "Adafruit_HTU21DF.h"
//#include "ZJ_ESP8266.h"
#include "ZJ_Display.h"
#include "ZJ_Heat_Hum.h"
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
AdafruitIO_Feed *temperature = io.feed("huzzah-temp");
AdafruitIO_Feed *humidity = io.feed("huzzah-hum");
