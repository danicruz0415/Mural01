#define countof(a) (sizeof(a) / sizeof(*(a)))

#include <Arduino.h>
#include "star/star.hpp"

Star stars[] = {
    /////////////////////////////////////////////////////////////////////////////
    // Moon                                                                    //
    /////////////////////////////////////////////////////////////////////////////
    Star(2),

    /////////////////////////////////////////////////////////////////////////////
    // Large Stars                                                             //
    /////////////////////////////////////////////////////////////////////////////

    // large star 1
    Star(4),
    // large star 2
    Star(13),
    // large star 3
    Star(14),
    /////////////////////////////////////////////////////////////////////////////
    // Small Stars                                                             //
    /////////////////////////////////////////////////////////////////////////////

    // small star 1
    Star(16),
    // small star 2
    Star(17),
    // small star 3
    Star(18),
    // small star 4
    Star(19),
    // small star 5
    Star(21),
    // small star 6
    Star(22),
    // small star 7
    Star(23),
    // small star 8
    Star(25),
    // small star 9
    Star(26),
    // small star 10
    Star(27),
    // small star 11
    Star(32),
    // small star 12
    Star(33),
    // Reserve pins: 5, 15
};

void setup()
{

  for (int i = 0; i < countof(stars); i++)
  {
    stars[i].init();
  }
  Serial.begin(9600);
  analogWriteResolution(10);
}

void loop()
{

  for (int i = 0; i < countof(stars); i++)
  {
    stars[i].update();
  }

  // update 60 times per second
  delay(16);
}