/*
Author: Fabio Godoy
Created at 2018-07-07
Last modified at 2019-12-25
Descripton: Responsible to handle the Rotary Encoder button. Button position and pressed button.
*/

#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>
#include <Encoder.h>
#include <SPI.h>

class RotaryEncoder
{
  public:
    enum ButtonPress {
      SHORT, LONG, VERY_LONG
    };
    RotaryEncoder(int dat_, int clk_);
    RotaryEncoder(int dat_, int clk_, int btn_);
    
    void registerBtnCallback(void (*callback_)(), int mode_);
    
    long getPosition();
    void setPosition(long pos_);

  private:
    Encoder* _encoder;
    long     _oldPosition;
    int      _btnPin;
    std::function<void(RotaryEncoder::ButtonPress btnPress_)> _buttonCallback;
    void btnCallback();
    
};
#endif