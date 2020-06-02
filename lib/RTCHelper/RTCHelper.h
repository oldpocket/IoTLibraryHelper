/*
Author: Fabio Andreozzi Godoy
e-mail: fabio.godoy@oldpocket.com
Created at 2019-05-11
Last modified at 2019-05-11
Descripton: Helper class for the RTC - clock sensor
*/

#ifndef RTCHelper_h
#define RTCHelper_h

#include <Arduino.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

class RTCHelper {
    public:
        RTCHelper(int dat_, int clk_, int rst_, bool setNTP_);
        RtcDateTime readDateTime();
        static void PrintDateTime(const RtcDateTime& dt_);
        bool saveToMemory(char data_[]);

    private:
        void updateWithNTP();
        void updateWithCompiledTime();
        bool _setNTP;
        RtcDS1302<ThreeWire>* _RTC;   
        ThreeWire _threeWire;
};

#endif