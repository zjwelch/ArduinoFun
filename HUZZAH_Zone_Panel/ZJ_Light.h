/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)

    These specific functions are related to operatoin of:
    
    GA1A1S202WP Log-scale Analog Light Sensor (GLAL)

    GLAL VCC -> HTH 3V3
    GLAL OUT -> HFE 2 (GPIO)
    GLAL GND -> HFE ?

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.0 - Test/Demo

  -Initialize the GLAL
  -Configure the light sensor
  -Display the light data to the screen
  -Push the data to IO feed
  
 ****************************************************/

 
