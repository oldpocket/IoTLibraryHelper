#include "LM35Handler.h"

LM35Handler::LM35Handler(int pin_) {
    _lastTemperature = 0;
    _pin = pin_;
}

byte LM35Handler::getTemperature(TempUnit tempUnit_) {
    if (_lastTemperature == 0) this->refresh();

    if (tempUnit_ == Fahrenheit) {
        return  _lastTemperature * 1.8 + 32.0;
    }

    return _lastTemperature;
}

void LM35Handler::refresh() {
    // To convert analog values to Celsius We have 3.3 V on our board and we know that 
    // output voltage of LM35 varies by 10 mV to every degree Celsius rise/fall. 
    // So , (A0*3300/10)/1023 = celsius

    float temp_celsius = (0.87 * analogRead(_pin) * 300.0) / 1024.0;   
    Serial.print("LM35 Temp = "); Serial.print(temp_celsius); Serial.println(" *C");
    _lastTemperature = temp_celsius;
}