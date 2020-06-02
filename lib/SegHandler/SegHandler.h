/*
Author: Fabio Andreozzi Godoy
e-mail: fabio.godoy@oldpocket.com
Created at 2019-05-11
Last modified at 2019-12-25
Descripton: Responsible to handle and display images in a TM1637Display.
*/

#ifndef SegHandler_h
#define SegHandler_h

#include <Arduino.h>
#include "TM1637Display.h"

// Print the Degrees Symbol in the segment 
const uint8_t DEGREES [ ] = {
  0x0, 0x0,
  SEG_A | SEG_B | SEG_G | SEG_F, // superscript o
  SEG_A | SEG_F | SEG_E | SEG_D, // C
};

class SegHandler {
    public:
        SegHandler(int pin1_, int pint2_); 
        
        // Generic Segment methods
        void clearSegment();
        void setBrightness(int brightness_);

        // Specific Segment methods
        void displayTemperature(int temperature_);
        void displayTime(int h_, int m_, int s_);

    private:
        //Control pin for TM1637 7 Seg module
        TM1637Display* _display;
};

#endif