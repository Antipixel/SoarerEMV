#include <input/touch.h>

Touch::Touch(Multiplexer *x, Multiplexer *y, uint8_t pin) : Input(x, y, pin) 
{
    pinMode(this->pin, INPUT_PULLUP);

    this->prevPoint = GridPoint(TOUCH_NONE, TOUCH_NONE);
}

void Touch::update()
{
    GridPoint point(this->getX(), this->getY());

    // If there has been no change, return
    if (point == prevPoint)
        return;

    if (point.isValid() && !prevPoint.isValid())
    {
        this->touchCallback(point);
    }
    else if (!point.isValid() && prevPoint.isValid())
    {
        this->exitCallback();
    }

    this->prevPoint = point;
}

void Touch::setTouchCallback(void (*touchCallback)(GridPoint p))
{
    this->touchCallback = touchCallback;
}

void Touch::setExitCallback(void (*exitCallback)())
{
    this->exitCallback = exitCallback;
}

int8_t Touch::getX()
{
    int8_t i;
    this->mpY->clear();
    for (i = 0; i < OUTPUT_COUNT; i++)
    {
        if (pollMultiplexer(this->mpX, i))
            return i;
    }
    this->mpX->clear();
    if (pollMultiplexer(this->mpY, 0))
        return 10;
        
    return -1;
}

int8_t Touch::getY()
{
    int8_t i;
    this->mpX->clear();
    for (i = 1; i < OUTPUT_COUNT; i++)
    {
        if (pollMultiplexer(this->mpY, i))
            return --i; // Adjust offset to compensate for Y axis starting at pin 1 
    }

    return -1;
}
