/*
Author: Fabio Godoy
Created at 2018-07-07
Descripton: Responsible to get Temperature and Humidity from DHT11 sensor.

Modification history:
---------------------
2019-06-30: Removed non used variable
2019-04-23: Code optimization
2018-07-07: First Version
*/

#ifndef DHT11Handler_h
#define DHT11Handler_h

#include <Arduino.h>
#include <SimpleDHT.h>

class DHT11Handler
{
  public:
    // default constructor
    DHT11Handler(int pin_);
    // update both, last temperature and last humidity
    void refresh();
    // return last temperature
    byte getTemperature();
    // return last humidity
    byte getHumidity();

  private:
    // save last temperature
    byte _lastTemperature;
    // save last humidity
    byte _lastHumidity;
    // DHT sensor (temperature and humidity)
    SimpleDHT11* _dht11;
    
};
#endif