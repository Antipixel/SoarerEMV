#include <input/multiplexer.h>

Multiplexer::Multiplexer()
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->d = 0;
}

Multiplexer::Multiplexer(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;

    this->setupPins();
    this->clear();
}

void Multiplexer::setupPins()
{
    pinMode(this->a, OUTPUT);
    pinMode(this->b, OUTPUT);
    pinMode(this->c, OUTPUT);
    pinMode(this->d, OUTPUT);
}

void Multiplexer::setOutput(uint8_t output)
{
    if (output >= OUTPUT_COUNT)
        return;

    digitalWrite(this->a, output & MASK_CH_A);
    digitalWrite(this->b, output & MASK_CH_B);
    digitalWrite(this->c, output & MASK_CH_C);
    digitalWrite(this->d, output & MASK_CH_D);
}

void Multiplexer::clear()
{
    digitalWrite(this->c, HIGH);
    digitalWrite(this->d, HIGH);
}