/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This library is based on the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  These specific functions are related to operatoin of:

    2.4" TFT FeatherWing ILI9341 Touchscreen (TFT)

    *Connections are hard bonded due to rear mounting and defined in config.h
    
    TFT STMPE_CS -> HFE 16
    TFT TFT_CS   -> HFE 0
    TFT TFT_DC   -> HFE 15
    TFT SD_CS    -> HFE 2
    //Used simultaneously for touch input and/or SD card read
    TFT MISO     -> HFE MISO/12
    TFT MOSI     -> HFE MOSI/13
    TFT SCK      -> HFE SCK/14

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.0 - Test/Demo

  +Initialize the HTH
  +Configure basic display
  +Test and demonstrate text refresh at a basic level
  
 ****************************************************/

// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and mosi = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
#define USE_SPI_HARD 1

//#ifdef ESP8266
#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2
//#endif

//////////////////////////////////////////////////////

#include <SPI.h>
#include "XilkaSpi.h"
#include "XilkaGFX.h"
#include "XilkaILI9341.h"

//CUSTOM COLORS
const uint16_t LIGHT_BLUE = 0x039F;

//INTERESTING COORDINATES
int TEMP_X = 165;
int TEMP_Y = 45;

int HUMD_X = 165;
int HUMD_Y = 65;

int status_X = 0;
int status_Y = 300;

typedef Xilka::ILI9341 DisplayType;

using namespace Xilka;

namespace {

const int8_t PIN_CS(0);  //Originally -1
const int8_t PIN_DC(15);
const int8_t PIN_RESET(-1);

DisplayType tft(PIN_RESET, PIN_DC, PIN_CS);

} // namespace

//Create SPI object
//spiBegin(PIN_CS, PIN_DC);

//Initialize the screen object
//tft.begin();

//0-4 for each roation direction
unsigned long setOrientation( int orientation )
{
    tft.setRotation(orientation);
}

unsigned long writeText( String text, int x, int y, int textSize, int newLine )
{
  const unsigned long start(micros());
  tft.setCursor(x, y);
  if (textSize > 0)
    tft.setTextSize(textSize);
  if (newLine < 1) {
    tft.print(text);
  } else {
    tft.println(text);
  }

  return micros() - start;
}
