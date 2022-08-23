#include <input/buttons.h>

Buttons::Buttons(Multiplexer *x, Multiplexer *y, uint8_t pin) : Input(x, y, pin) 
{
    this->prevState = ButtonID::NONE;

    pinMode(this->pin, INPUT);
}

ButtonID Buttons::getButton()
{
    for (int8_t i = 0; i < BUTTON_COUNT; i++)
    {
        if (pollMultiplexer(this->mpX, i))
            return (ButtonID)i;
    }
    return ButtonID::NONE;
}

void Buttons::update()
{
    // Get the current state of the buttons
    ButtonID state = this->getButton();

    // If there was no change, ignore
    if (state == this->prevState)
        return;

    if (prevState == ButtonID::NONE)
    {
        (*(this->pressCallback))(state);
    }
    else if (state == ButtonID::NONE)
    {
        (*(this->releaseCallback))(prevState);
    }
    else
    {
        // this would mean straight from one button to another?
        // I guess just trigger the release from the old and trigger the 
        // press event for the current
    }

    this->prevState = state;
}

void Buttons::setButtonPressCallback(void (*pressCallback)(ButtonID))
{
    this->pressCallback = pressCallback;
}

void Buttons::setButtonReleaseCallback(void (*releaseCallback)(ButtonID))
{
    this->releaseCallback = releaseCallback;
}