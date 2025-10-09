#include <Arduino.h>

class Transition
{
private:

    // value tracking
    double _targetValue;
    double _startValue;

    // timing properties
    unsigned long _currentTime;
    unsigned long _startTime;
    unsigned long _duration;
public:
    Transition();
    double getCurrentValue();
    void setCurrentValue(double currentValue);
    unsigned long getElapsedTime();
    void setTargetValue(double targetValue, unsigned long duration);
    double getTargetValue();
    double getStartValue();
    double getFactor(double completionPercentage);
    unsigned long getDuration();
    bool finished();
};