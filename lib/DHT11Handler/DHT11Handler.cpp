#include "DHT11Handler.h"

DHT11Handler::DHT11Handler(int pin_) {
    _dht11 = new SimpleDHT11(pin_);
    _dht11 ? Serial.println("DHT11 ok") : Serial.println("DHT11 error");
    _lastHumidity = 0;
    _lastTemperature = 0;
}

byte DHT11Handler::getHumidity() {
    if (_lastHumidity == 0) this->refresh();
    return _lastHumidity;
}

byte DHT11Handler::getTemperature() {
    if (_lastTemperature == 0) this->refresh();
    return _lastTemperature;
}

void DHT11Handler::refresh() {
    // read without samples.
    byte temperature = 0;
    byte humidity = 0;
    int err = SimpleDHTErrSuccess;
    if (!_dht11) {
        Serial.println("DHT11 not initialized");
        return;
    }
    if ((err = _dht11->read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
        Serial.print("Read DHT11 failed, err="); Serial.println(err); 
        delay(1000);
        return;
    }

    Serial.print("Sample OK: ");
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" H");

    _lastTemperature = temperature;
    _lastHumidity = humidity;
}