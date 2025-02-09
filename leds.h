#ifndef LEDS_H
#define LEDS_H

#include <Adafruit_NeoPixel.h>

class Leds {
public:
    Leds(int pin, int count);
    void begin();
    void show();

private:
    Adafruit_NeoPixel leds;
};

#endif
