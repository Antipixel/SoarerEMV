#ifndef MULTIPLEXER_H_
#define MULTIPLEXER_H_

#include <Arduino.h>

#define OUTPUT_COUNT 10
#define OUTPUT_DISABLED -1
#define MASK_CH_A 0b0001
#define MASK_CH_B 0b0010
#define MASK_CH_C 0b0100
#define MASK_CH_D 0b1000

class Multiplexer
{
private:
    uint8_t a; 
    uint8_t b;
    uint8_t c;
    uint8_t d;
    void setupPins();
public:
    Multiplexer();
    Multiplexer(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
    void setOutput(uint8_t output);
    void clear();
};

#endif