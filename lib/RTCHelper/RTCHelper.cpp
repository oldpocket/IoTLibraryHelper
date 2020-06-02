#include "RTCHelper.h"

#define countof(a) (sizeof(a) / sizeof(a[0]))

RTCHelper::RTCHelper(int dat_, int clk_, int rst_, bool setNTP_) : 
    _threeWire(dat_, clk_, rst_) {

    _setNTP = setNTP_;

    _RTC = new RtcDS1302<ThreeWire>(_threeWire);
    _RTC->Begin();

    if (_RTC->GetIsWriteProtected()) {
        Serial.println("RTC was write protected, enabling writing now");
        _RTC->SetIsWriteProtected(false);
    }

    if (!_RTC->GetIsRunning()) {
        Serial.println("RTC was not actively running, starting now");
        _RTC->SetIsRunning(true);
    }

    // Update date/time using NTP server or binary Compiled Time?
    _setNTP ? updateWithNTP() : updateWithCompiledTime();

    PrintDateTime(_RTC->GetDateTime());
}

void RTCHelper::updateWithCompiledTime() {
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    
    Serial.print("RTC Date-time: "); PrintDateTime(compiled); Serial.println();

    if (_RTC->GetDateTime() < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        _RTC->SetDateTime(compiled);
    }
}

void RTCHelper::updateWithNTP() {
    WiFiUDP ntpUDP;

    // By default 'pool.ntp.org' is used with 60 seconds update interval and
    // no offset
    NTPClient timeClient(ntpUDP);
    int timezone = -3 * 3600; // Brasilia
    timeClient.setTimeOffset(timezone);
    timeClient.begin();
    
    // Note: sometimes the NTP Client retrieves 1970. To ensure that doesn’t 
    // happen we need to force the update.
    while(!timeClient.update()) {
        timeClient.forceUpdate();
    }


    long actualTime = timeClient.getEpochTime();
    _RTC->SetDateTime(actualTime);

    Serial.print("NTP date/time: "); Serial.println(timeClient.getFormattedTime()); 
}

bool RTCHelper::saveToMemory(char data_[]) {
    
    // Store something in memory on the RTC
    uint8_t count = sizeof(data_);
    uint8_t written = _RTC->SetMemory((const uint8_t*)data_, count); // this includes a null terminator for the string
    if (written != count) {
        Serial.print("something didn't match, count = ");
        Serial.print(count, DEC);
        Serial.print(", written = ");
        Serial.print(written, DEC);
        Serial.println();
        return false;
    }

    return true;
}

RtcDateTime RTCHelper::readDateTime() {
    if (!_RTC->GetIsRunning()) Serial.println("RTC is not running....");
    
    // PrintDateTime(_RTC->GetDateTime());
    return _RTC->GetDateTime();
}

void RTCHelper::PrintDateTime(const RtcDateTime& dt) {
    char datestring[20];;

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.println(datestring);
}


