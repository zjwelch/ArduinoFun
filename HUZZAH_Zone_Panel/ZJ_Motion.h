/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  These specific functions are related to operatoin of:

  PIR Motion Sensor (PMS)

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  Output is digital and pulls voltage high when motion is detected.
  The logic for use in this project is to create a decay timer and
  reset the timer each time motion is detected. Thus "active" motion
  can be tracked. Once the decay reaches zero it is clear motion has
  stopped until new motion is detected. If no motion is detected
  within a set amount of time, the assumption is nothing is present.

  vA0.1.0 - Test/Demo

  +Initialize the PMS
  +Configure the decay cycle and activity flag
  +Test sensor with output to serial and verify decay
  
 ****************************************************/

 #ifndef ZJ_Motion_H
 #define ZJ_Motion_H
 #define PIR_INTPUT_PIN "12";

 /////////////////////////////////////////////////////

 include <Wire.h>

 class PIR_Sensor
 {
  private:
  
    int input;
    int pinState;

  public:

    void PIR_Sensor();
    bool motionDetected();
    
 };

#endif
