#ifndef BUTTONS_H
#define BUTTONS_H

class Buttons {
public:
    Buttons(int pinA, int pinB);
    void attachInterrupts(void (*funcA)(), void (*funcB)());

private:
    int pinA;
    int pinB;
};

#endif
