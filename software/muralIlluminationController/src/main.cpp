#define countof(a) (sizeof(a) / sizeof(*(a)))

#include <Arduino.h>
#include "star/star.hpp"

Star stars[] = {
    /////////////////////////////////////////////////////////////////////////////
    // Moon                                                                    //
    /////////////////////////////////////////////////////////////////////////////
    Star(32),

    /////////////////////////////////////////////////////////////////////////////
    // Large Stars                                                             //
    /////////////////////////////////////////////////////////////////////////////

    // large star 1
    Star(25),
    // large star 2
    Star(26),
    // large star 3
    Star(33),
    /////////////////////////////////////////////////////////////////////////////
    // Small Stars                                                             //
    /////////////////////////////////////////////////////////////////////////////

    // small star 1
    Star(2),
    // small star 2
    Star(4),
    // small star 3
    Star(16),
    // small star 4
    Star(17),
    // small star 5
    Star(18),
    // small star 6
    Star(19),
    // small star 7
    Star(21),
    // small star 8
    Star(22),
    // small star 9
    Star(23),
    // small star 10
    Star(13),
    // small star 11
    Star(14),
    // small star 12
    Star(27),
    // Reserve pins: 5, 15
};

void setup()
{
  
  analogWriteResolution(10);
  for (int i = 0; i < countof(stars); i++)
  {
    stars[i].init();
  }
}

void loop()
{

  for (int i = 0; i < countof(stars); i++)
  {
    stars[i].update();
  }

  // update 30 times per second
  delay(32);
}