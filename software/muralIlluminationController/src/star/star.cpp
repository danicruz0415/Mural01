#include <Arduino.h>
#include "star.hpp"

Star::Star(uint8_t pinNumber) {
    _pinNumber = pinNumber;
    _brightnessController = Transition();
    
};

void Star::init()
{
    _currentBrightness = 1023;
    _brightnessController.setCurrentValue(_currentBrightness);
    
    pinMode(_pinNumber, OUTPUT);
};

void Star::update()
{

    // if the transition finished, chose a new target value
    if (_brightnessController.finished()) {
        const double lastStartValue = _brightnessController.getStartValue();
        const double lastTargetValue = _brightnessController.getTargetValue();

        if (lastTargetValue > lastStartValue){
            // star was getting brighter. Let the star at full brightness for a while
             _brightnessController.setTargetValue(lastTargetValue, random(1000,5000));
        }
        
        else if (lastTargetValue < lastStartValue){
            // star was getting dimmer. Set the star to return to full brightness
            // make sure the "turning on" lasts as long as the dimming
            const unsigned long lastDuration = _brightnessController.getDuration();
             _brightnessController.setTargetValue(lastStartValue, lastDuration);
        } else {
            // the star was static. Set it to dim
             _brightnessController.setTargetValue(random(0,250), random(100,500));
            //_brightnessController.setTargetValue(0, 7000);
        }
        
    }

    double newBrightness = _brightnessController.getCurrentValue();
    if (newBrightness != _currentBrightness) {
        _currentBrightness = newBrightness;
        analogWrite(_pinNumber, newBrightness);
    }

}
