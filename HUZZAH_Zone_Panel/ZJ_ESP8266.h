/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: Jeremy Schiefer
  
  This library is based on the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  These specific functions are related to operatoin of:

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.0 - Test/Demo

  +Initialize the HTH
  +Configure basic display
  +Test and demonstrate text refresh at a basic level

////////////////////////////////////////////////////////////////////////////

#include <ESP8266WiFi.h>
#include "AdafruitIO_WiFi.h"
#include "ZJ_Secrets.h"

//Create IO API feed object (values defined in Secrets header)
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
