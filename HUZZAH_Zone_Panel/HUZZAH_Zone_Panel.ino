/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.
  
  Written by:   Zachary J Welch
  Contributors: Jeremy Schiefer
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  Attached devices:

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
  
  HTU21D-F Humidity & Temp Sensor (HTH)

    HTH VIN -> HFE 3V
    HTH GND -> HFE GND
    HTH SDA -> HFE SDA/4
    HTH SCL -> HFE SCL/5

  GA1A1S202WP Log-scale Analog Light Sensor (GLAL)

    GLAL VCC -> HTH 3V3
    GLAL OUT -> HFE 2 (GPIO)
    GLAL GND -> HFE ?

  SPW2430 Silicon MEMS Microphone (SSMM)

  PIR Motion Sensor (PMS)

  Power provided by USB 5v power AND/OR LiPoly 3.7v 1200mAh battery
  connected to LM3671 3.3v Buck Converter Breakout - 600mA max

  ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.1 - First steps

  -Rewrite working code in personally preffered format
  -Rewrite comments and docs accordingly
  +Reconfigure correct wireless settings (home)
  +Replace wasteful delay() function with custom wait() function
  -Set more reasonable data point timer
  -Add initilization for GLAL
  -Create new feed for GLAL and test
  !does not connect to wifi properly

  vA0.1.0 - Test/Demo

  +Configure local wireless settings (not home)
  +Initialize the HTH
  +Open a feed session with http://io.adafruit.com
  +Push data points to io.adafruit feed on timer

 ****************************************************/

#include "ZJ_config.h"

int num = 0;

void setup() {
  
  Serial.begin(115200);

  //Initialize the TFT Screen
  //tft.begin();
  //tft.setRotation(1);
  setOrientation(0);
  //tft.fillScreen(ILI9341_BLACK);
  tft.fillScreen(tft.BLACK);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  //Serial.print("Connecting to ");
  //Serial.println(ssid);
  
  //WiFi.begin(ssid, password);

  //while (WiFi.status() != WL_CONNECTED) {
  //  delay(500);
  //  Serial.print(".");
  //}

  //Serial.println("");
  //Serial.println("WiFi connected");  
  //Serial.println("IP address: ");
  //Serial.println(WiFi.localIP());
/*  
  Serial.println("HTU21D-F test");

  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }*/

  //writeText(("test:"), 0, 0, 6, 0 );
}

void loop() {

  //Create SPI object
  spiBegin();

  //Initialize the screen object
  tft.begin();

  io.run();
  setOrientation(0);
  
//  tft.fillScreen(ILI9341_BLACK);
//  tft.setCursor(0, 0);
  
  //sensors_event_t event;
  //htu.readTemperature().getEvent(&event);
//  float temp = htu.readTemperature();

  //float celsius = event.temperature;
//  float celsius = temp;
//  float fahrenheit = (celsius * 1.8) + 32;

  //htu.readHumidity().getEvent(&event);
//  float humi = htu.readHumidity();

/*
  tft.setTextColor(ILI9341_BLUE);
  tft.setTextSize(8);
  tft.print(fahrenheit);tft.println("F");

  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(6);
  tft.print(humi);tft.println("%");

  //debug
  Serial.print("fahrenheit: ");Serial.print(fahrenheit);Serial.println("F");
  Serial.print("humidity: ");Serial.print(humi);Serial.println("%");

  // save fahrenheit (or celsius) to Adafruit IO
  temperature->save(fahrenheit);

  // save humidity to Adafruit IO
  //humidity->save(event.relative_humidity);
  humidity->save(humi);
*/
  //Serial.print("Temp: "); Serial.print(htu.readTemperature());
  //Serial.print("\t\tHum: "); Serial.println(htu.readHumidity());

  tft.setCursor(130, 0);
  tft.print(num);
  num++;
  
  delay(2000);
  
}
