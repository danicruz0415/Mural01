#include <Arduino.h>
#include "transition.hpp"


Transition::Transition()
{
    
}


void Transition::setCurrentValue(double currentValue){
    _startValue = currentValue;
    _targetValue = currentValue;
    _duration = 0;
    _startTime = millis();
}

double Transition::getCurrentValue()
{

    if (finished()) {
        return _targetValue;
    }
    
    double completionPercentage = (double)getElapsedTime() / _duration;
    double deltaValue = _targetValue - _startValue;
    return _startValue + deltaValue * getFactor(completionPercentage);
}


// https://easings.net/#easeInOutQuad 
[[nodiscard]]
double Transition::getFactor(double completionPercentage)
{
    if (completionPercentage < 0.5)
    {
        return 2 * pow(completionPercentage, 2);
    }
    return 1 - pow(-2 * completionPercentage + 2, 2) / 2;
}

[[nodiscard]]
unsigned long Transition::getElapsedTime()
{
    return millis() - _startTime;
}

[[nodiscard]]
unsigned long Transition::getDuration()
{
    return _duration;
}

void Transition::setTargetValue(double targetValue, unsigned long duration)
{
    // the animation starts at the current state
    _startValue = getCurrentValue();
    _targetValue = targetValue;
    _duration = duration;
    _startTime = millis();
}


double Transition::getTargetValue() {
    return _targetValue;
}

double Transition::getStartValue() {
    return _startValue;
}

bool Transition::finished() {
    unsigned long timeElapsed = getElapsedTime();
    return timeElapsed >= _duration;
}

