#include <Arduino.h>
#include "transition/transition.hpp"


class Star
{
private:
    int _pinNumber;
    Transition _brightnessController;
    double _currentBrightness;
public:
    Star(uint8_t pinNumber);
    void init();
    void update();
};

