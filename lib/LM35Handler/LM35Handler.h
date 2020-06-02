/*
Author: Fabio Godoy
Created at 2019-12-23
Descripton: Responsible to get Temperature from a LM35 sensor.

Modification history:
---------------------
2019-12-23: First Version
*/

#ifndef LM35Handler_h
#define LM35Handler_h

#include <Arduino.h>

enum TempUnit {Celsius, Fahrenheit};

class LM35Handler
{
  public:
    // default constructor
    LM35Handler(int pin_);
    // update last temperature
    void refresh();
    // return last temperature
    byte getTemperature(TempUnit tempUnit_);

  private:
    // save last temperature
    byte _lastTemperature;

    // analog PIN
    int _pin;
};
#endif