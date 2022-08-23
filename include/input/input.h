#ifndef INPUT_H_
#define INPUT_H_

#include <Arduino.h>
#include <input/multiplexer.h>

class Input
{
protected:
    Multiplexer *mpX;
    Multiplexer *mpY;
    uint8_t pin;
public:
    Input(Multiplexer *x, Multiplexer *y, uint8_t pin);
    virtual void update() = 0;
protected:
    bool pollMultiplexer(Multiplexer *m, uint8_t output);
    
};

#endif