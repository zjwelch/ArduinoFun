# https://github.com/zjwelch/ArduinoFun

/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, NY, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This build is for the HUZZAH FEATHER ESP8266 Adafruit board (HFE)
  *Will later be adapted for the new Adafruit HUZZAH ESP32 FEATHER (HE32)

  ****************** Description ********************

  Core Sketchfile to accomplish the following:
  
  This will be a prototype sensor array to monitor temp/humi, motion, sound,
  and light, report that data back to a Raspberry Pi "Zone Controller Brain" (ZCB),
  and also provide a basic touchscreen user interface for directect remote interaction
  to the ZCB.
  
  The purpose is to make realtime and dynamic decisions that will interact with
  electronic damper controls and a Nest smart thermostat system.
  
  Version control:
  
  //+ completed  - pending  ! acknowledged bug  * self note 

  vA0.1.1 - First steps

  -Rewrite working code in personally preffered format
  *will need a compile test after re-write
  +Rewrite comments and docs accordingly
  +Break out sensors/devices into their own libraries
  +Reconfigure correct wireless settings
  +Replace wasteful delay() function with proto threading

  vA0.1.0 - Test/Demo

  +Configure local wireless settings
  +Initialize the HTH
  +Open a feed session with http://io.adafruit.com
  +Push data points to io.adafruit feed on timer

  ****************** DISCLAIMER ********************

IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS,
ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF
REGENTS HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED 
HEREUNDER IS PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE ANY
ADDITIONAL INFORMATION, MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR 
MODIFICATIONS OF ANY KIND TO ANY PARTIES, COLLECTIVES OR ENTITIES.
