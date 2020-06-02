#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(int dat_, int clk_) : RotaryEncoder(dat_, clk_, -1) {
    
}

RotaryEncoder::RotaryEncoder(int dat_, int clk_, int btn_) {
    _encoder = new Encoder(dat_, clk_);
    _encoder ? Serial.println("Rotary Encoder ok") : Serial.println("Rotary Encoder error");
    _oldPosition  = -999;
    _btnPin = btn_;
}

void RotaryEncoder::registerBtnCallback(void (*callback_)(), int mode_) {
    if (_btnPin < 0) return;

    // Prepare the Rotary Encoder
    pinMode(_btnPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_btnPin), callback_, mode_);
}

long RotaryEncoder::getPosition() {

    long newPosition = _encoder->read();
    if (newPosition != _oldPosition) {
        _oldPosition = newPosition;
        Serial.println(newPosition);
    }

    return newPosition;
}

void RotaryEncoder::setPosition(long pos_) {
    _encoder->write(pos_);
}