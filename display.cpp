#include "display.h"

Display::Display(int width, int height, TwoWire *wire, int reset) : display(width, height, wire, reset) {}

void Display::clearDisplay() {
    display.clearDisplay();
    display.display();
}

void Display::displayMessage(String msg) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 10);
    display.println(msg);
    display.display();
}
