/*
Author: Fabio Andreozzi Godoy
e-mail: fabio.godoy@oldpocket.com
Created at 2019-05-11
Last modified at 2019-05-11
Descripton: Responsible to check if the _tap button_ was tapped or not.
*/

#ifndef TapButtonHandler_h
#define TapButtonHandler_h

#include <Arduino.h>

class TapButtonHandler {
    public:
        TapButtonHandler(int pin_); 
        bool checkTapButton();
        void setFrequency(int freq_);
        int getFrequency();

    private:
        int _tapButtonPin;     // the pin that the pushbutton is attached to
        // Variables will change:
        int _buttonPushCounter; // counter for the number of button presses
        int _buttonState;      // current state of the button
        int _lastButtonState;  // previous state of the button
        // We need to normalize the frequency of taps, otherwise we get TRUE all the time
        int _frequency;
};

#endif