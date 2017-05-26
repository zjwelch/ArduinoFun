/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)

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

//int num = 0;

void setup() {
  
  Serial.begin(115200);

  //Initialize DHT sensor
  dht.begin();

  //Initialize the TFT Screen
  spiBegin();
  tft.begin();
  //tft.setRotation(1);
  //setOrientation(0);
  //tft.fillScreen(ILI9341_BLACK);
  tft.fillScreen(tft.BLACK);
  tft.setTextColor(tft.WHITE,tft.BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(3);
  tft.print("GUEST BEDROOM");
  tft.setCursor(0, TEMP_Y);
  tft.setTextSize(2);
  tft.print("Temperature: ");
  tft.setCursor(0, HUMD_Y);
  tft.setTextSize(2);
  tft.print("Humidiy: ");

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  tft.setCursor(status_X,status_Y);
  tft.setTextSize(1);
  tft.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  tft.setCursor(status_X,status_Y);
  tft.setTextSize(1);
  tft.print(io.statusText());
  tft.println(" ");

  //UDP connection to node.js server
  Serial.println("Connecting to node.js");
  Udp.begin(arduinoPort);
  Serial.println("Connected");
  

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
  //piBegin();

  //Initialize the screen object
  //tft.begin();

  io.run();
  //setOrientation(0);
  
//  tft.fillScreen(ILI9341_BLACK);
//  tft.setCursor(0, 0);
  
  sensors_event_t event;
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

  //tft.setCursor(130, 0);
  //tft.print(num);
  //num++;
  //delay(2000);
  
  //READ SENSOR DATA
  float f = dht.readTemperature(true);
  float h = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //SAVE TO ADAFRUIT.IO
  temperature->save(f);
  humidity->save(h);

  //SEND TO NODE.JS
  Udp.beginPacket(receiverIP, receiverPort); //start udp packet

  //MAKE JSON TO SEND VIA UDP
  String line;
  line = ("{\"boardID\":001 \"temperature\":");
  line += String(f,1);
  line += (" \"humidity\":");
  line += String(h,1);
  line += "}";
  
  Udp.print(line);
  Udp.endPacket(); // end packet

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(f);
  Serial.print(" *F\n");
  
  tft.setCursor(TEMP_X, TEMP_Y);
  tft.setTextSize(2);
  tft.print(f,1);
  tft.setTextSize(1);
  tft.print((char)223);
  tft.setTextSize(2);
  tft.print("F");

  tft.setCursor(HUMD_X, HUMD_Y);
  tft.print(h,1);
  tft.print("%");

  tft.setTextSize(1);
  for (int i=10; i>=0; i--){
    tft.setCursor(status_X,status_Y);
    tft.print("Next update in ");
    tft.print(i);
    tft.print(" seconds.");
    delay(1000);
    }


}
