/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)
*/

#include "ZJ_config.h"

//int num = 0;

void setup() {
  
  Serial.begin(115200);

  //Initialize DHT sensor
  dht.begin();

  //Initialize the TFT Screen
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE,ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(3);
  tft.print("GUEST BEDROOM");
  tft.setCursor(0, TEMP_Y);
  tft.setTextSize(2);
  tft.print("Temperature: ");
  tft.setCursor(0, HUMD_Y);
  tft.setTextSize(2);
  tft.print("Humidiy: ");

  //Draw the info box
  tft.drawRect(INFOBOX_X, INFOBOX_Y, INFOBOX_W, INFOBOX_H, ILI9341_WHITE);
  tft.setCursor(INFOTXT_X,INFOTXT_Y);
  tft.print("Info");

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
  
}

void loop() {

  io.run();
  
  sensors_event_t event;
  
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
