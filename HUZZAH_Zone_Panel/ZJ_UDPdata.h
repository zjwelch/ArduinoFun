/**************************************************************************

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  These functions are intended for use with HUZZAH FEATHER ESP8266 from adafruit (HFE)


 ****************** Description ********************

  Core header for encapsulating a datapacket to push data updates to ZoneMaster
 
  + completed  - pending  ! acknowledged bug  * self note

  vA0.1.0 - Test/Demo

  +Include initial libraries
  +Configure basic constructors for the various devices and sensors

 ***********************************************************************/

//#include <SPI.h>
//#include <Ethernet.h>
#include <EthernetUdp.h>
#include <WiFiUdp.h>

unsigned int arduinoPort = 8888;      // port of Arduino

IPAddress receiverIP(10, 10, 20, 227); // IP of zone-collector
unsigned int receiverPort = 6000;      // Port node.js server listening on

WiFiUDP Udp;
