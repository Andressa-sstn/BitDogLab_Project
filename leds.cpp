#include "leds.h"

Leds::Leds(int pin, int count) : leds(count, pin, NEO_GRB + NEO_KHZ800) {}

void Leds::begin() {
    leds.begin();
}

void Leds::show() {
    leds.show();
}
