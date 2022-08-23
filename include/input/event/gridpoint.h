#ifndef GRIDPOINT_H_
#define GRIDPOINT_H_

#include <Arduino.h>

#define TOUCH_NONE -1

class GridPoint
{
public:
    int8_t x;
    int8_t y;
    GridPoint();
    GridPoint(int8_t x, int8_t y);
    bool isValid();
    bool operator ==(GridPoint a);
};

#endif