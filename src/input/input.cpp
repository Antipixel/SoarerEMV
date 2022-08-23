#include <input/input.h>

Input::Input(Multiplexer *x, Multiplexer *y, uint8_t pin)
{
    this->mpX = x;
    this->mpY = y;
    this->pin = pin;
}

bool Input::pollMultiplexer(Multiplexer *m, uint8_t output)
{
    m->setOutput(output);
    delay(1);
    uint8_t state = digitalRead(this->pin);
    delay(1);
    return state;
}
