#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <input/input.h>

#define BUTTON_COUNT 7

enum ButtonID: int8_t
{
    NONE = -1,
    MAP = 0,
    MENU = 1,
    LOCATION = 2,
    INFORMATION = 3,
    AUDIO = 4,
    MONITOR = 6,
    AIRCON = 5,
};

class Buttons: public Input
{
private:
    ButtonID prevState;
    void (*pressCallback)(ButtonID);
    void (*releaseCallback)(ButtonID);
public:
    Buttons(Multiplexer *x, Multiplexer *y, uint8_t pin);
    void update();
    void setButtonPressCallback(void (*pressCallback)(ButtonID));
    void setButtonReleaseCallback(void (*releaseCallback)(ButtonID));
private:
    ButtonID getButton();
};

#endif