/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2

  Display is 240 x 320
*/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ILI9341.h> // Hardware-specific library
#include <Adafruit_STMPE610.h>

#define USE_SPI_HARD 1

#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2

//INTERESTING COORDINATES
int TEMP_X = 165;
int TEMP_Y = 45;

int HUMD_X = 165;
int HUMD_Y = 65;

int INFOBOX_X = 15;
int INFOBOX_Y = 225;
int INFOBOX_W = 210;
int INFOBOX_H = 50;

int INFOTXT_X = INFOBOX_X + 5;
int INFOTXT_Y = INFOBOX_Y + (INFOBOX_H / 2) - 3;

int status_X = 0;
int status_Y = 300;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);


