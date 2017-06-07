/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: srcnet2
  
  This library is based on the HUZZAH FEATHER ESP8266 adafruit board (HFE)

  These specific functions are related to operatoin of:

   HTU21D-F Humidity & Temp Sensor (HTH)

    HTH VIN -> HFE 3V
    HTH GND -> HFE GND
    HTH SDA -> HFE SDA/4
    HTH SCL -> HFE SCL/5

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.0 - Test/Demo

  +Initialize the HTH
  +Configure basic display
  +Test and demonstrate text refresh at a basic level
  
 ****************************************************/

#ifndef ZJ_HEAT_HUM_H
#define ZJ_HEAT_HUM_H

#define DHTPIN 4
#define DHTTYPE DHT11

/////////////////////

#include "Adafruit_HTU21DF.h"
#include "DHT.h"

class heatHumSensor {

  private:
  
    varchar(3) sensorType;
  
  public:
    
    void heatHumSensor( varchar(3) type );
    float getC();
    float getF();
    float getH();

};

#endif

#include "ZJ_HEAT_HUM_H"

void heatHumSensor::heatHumSensor( varchar(3) type ) {

  if( type == 'DHT' ) {

    sensorType = type;
    DHT genericDHT(DHTPIN, DHTTYPE);
    sensor = static_cast<DHT>(*sensor);
    *sensor = &genricDHT;
    
  } else if ( type == 'HTU' ) {

    Adafruit_HTU21DF genericHTU = Adafruit_HTU21DF();
    sensor = static_cast<Adafruit_HTU21DF>(*sensor);
    *sensor = &Adafruit_HTU21DF;
    
  }
  
  return false;
  
}

float heatHumSensor::getC( void ) {

  
  celcius = sensor.readTemperature();
  return celcius;

}

float heatHumSensor::getF( void ) {

  faranheit = (( sensor.readTemperature() * 1.8 ) + 32 );
  return faranheit;

}

float heatHumSensor::getH( void ) {

  humidity = sensor.readHumidity();
  return humidity;

}


