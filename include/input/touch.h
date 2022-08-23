#ifndef TOUCH_H_
#define TOUCH_H_

#include <input/input.h>
#include <input/event/gridpoint.h>

class Touch: public Input
{
private:
    GridPoint prevPoint;
    void (*touchCallback)(GridPoint p);
    void (*exitCallback)();
public:
    Touch(Multiplexer *x, Multiplexer *y, uint8_t pin);
    void update();
    void setTouchCallback(void (*touchCallback)(GridPoint p));
    void setExitCallback(void (*exitCallback)());
private:
    int8_t getX();
    int8_t getY();
};

#endif