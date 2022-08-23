#include <input/event/gridpoint.h>


GridPoint::GridPoint()
{
    this->x = TOUCH_NONE;
    this->y = TOUCH_NONE;
}

GridPoint::GridPoint(int8_t x, int8_t y)
{
    this->x = x;
    this->y = y;
}

bool GridPoint::isValid()
{
    return (this->x != TOUCH_NONE && this->y != TOUCH_NONE);
}

bool GridPoint::operator ==(GridPoint a)
{
    return (this->x == a.x && this->y == a.y);
}