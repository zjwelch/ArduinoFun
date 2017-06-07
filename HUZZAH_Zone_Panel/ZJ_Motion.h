/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  These specific functions are related to operatoin of:

  PIR Motion Sensor (PMS)

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  vA0.1.0 - Test/Demo

  +Initialize the PMS
  +Configure the decay cycle and activity flag
  +Test sensor with output to serial and verify decay
  
 ****************************************************/

#ifndef ZJ_Motion_H
#define ZJ_Motion_H
#define PIR_INTPUT_PIN 12;

/////////////////////////////////////////////////////

include <Wire.h>

class PIR_Sensor {
  
  private:
  
    int input;
    int pinState;

  public:

    void PIR_Sensor();
    bool motionDetected();
    
 };

#endif
