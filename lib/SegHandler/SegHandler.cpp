#include "SegHandler.h"

SegHandler::SegHandler(int clk_, int dio_) {
  _display = new TM1637Display(clk_, dio_);
  _display ? Serial.println("Seg Display ok") : Serial.println("Seg Display error");
  _display->setBrightness(0xff); //set the diplay to maximum brightness
  //_display->setBrightness(0x0a); //not so bright
}

//To clear all segments of display
void SegHandler::clearSegment() {
  uint8_t clear_segment[] = { 0x00, 0x00, 0x00, 0x00  };
  _display->setSegments(clear_segment);
}

void SegHandler::setBrightness(int brightness_) {
  // 0xff : maximum brightness
  // 0x0a : not so bright
  _display->setBrightness(brightness_);
}

void SegHandler::displayTemperature(int temperature_) {
  _display->setSegments(DEGREES); //Display the Variable value;
  _display->showNumberDec(temperature_,false,2,0);
  delay (4000);  
}

void SegHandler::displayTime(int h_, int m_, int s_) {

    // Print Data array - Start
    uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
    
    data[0] = _display->encodeDigit(h_ / 10);
    data[1] = _display->encodeDigit(h_ % 10) | (s_ % 2 ? 0x80 : 0x00); // (s % 2 ? 0x80 : 0x00) liga e desliga a coluna central, se for par ou impar
    data[2] = _display->encodeDigit(m_ / 10);
    data[3] = _display->encodeDigit(m_ % 10);
    _display->setSegments(data);
}