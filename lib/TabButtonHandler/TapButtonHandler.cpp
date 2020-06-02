#include "TapButtonHandler.h"

TapButtonHandler::TapButtonHandler(int pin_) {
  // initialize the button pin as a input:
  pinMode(pin_, INPUT);

  _tapButtonPin = pin_;
  _buttonPushCounter = 0;
  _buttonState = 0;
  _lastButtonState = 0;
  _frequency = 1;
}

bool TapButtonHandler::checkTapButton() {
  // read the pushbutton input pin:
  _buttonState = digitalRead(_tapButtonPin);

  // compare the buttonState to its previous state
  if (_buttonState != _lastButtonState) {
    // if the state has changed, increment the counter
    if (_buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      _buttonPushCounter++;
      Serial.println("Tap button: ON state");
      Serial.print("Number of tap button pushes:  "); Serial.println(_buttonPushCounter);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("Tap button: OFF state"); 
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  _lastButtonState = _buttonState;


  // Return TRUE every "_frequency" button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if (_buttonPushCounter > 0 && _buttonPushCounter % _frequency == 0) {
    _buttonPushCounter = 0;
    return true;
  } else {
    return false;
  }

}
