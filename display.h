#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Display {
public:
    Display(int width, int height, TwoWire *wire, int reset);
    void clearDisplay();
    void displayMessage(String msg);

private:
    Adafruit_SSD1306 display;
};

#endif
