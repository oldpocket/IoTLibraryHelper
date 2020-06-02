/*
Author: Fabio Andreozzi Godoy
e-mail: fabio.godoy@oldpocket.com
Created at 2019-05-11
Last modified at 2019-05-11
Descripton: Helper class for the RTC - clock sensor
*/

#ifndef WifiHelper_h
#define WifiHelper_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

class WifiHelper {
    public:
        static void Start(const char* SSID_, const char* password_);
    private:
};

#endif