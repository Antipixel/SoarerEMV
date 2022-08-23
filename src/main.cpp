#include <Arduino.h>
#include <Keyboard.h>
#include <AbsMouse.h>
#include <aircon/aircon.h>
#include <input/multiplexer.h>
#include <input/buttons.h>
#include <input/touch.h>

#define PIN_CLOCK 0
#define PIN_DATA 10
#define PIN_CLEAR 1

#define PIN_A 7
#define PIN_B 6
#define PIN_X_C 5
#define PIN_X_D 4
#define PIN_Y_C 3
#define PIN_Y_D 2

#define PIN_BUTTONS 8
#define PIN_TOUCH 9

Aircon aircon(PIN_CLOCK, PIN_DATA, PIN_CLEAR);

Multiplexer chipX(PIN_A, PIN_B, PIN_X_C, PIN_X_D);
Multiplexer chipY(PIN_A, PIN_B, PIN_Y_C, PIN_Y_D);

Touch touch(&chipX, &chipY, PIN_TOUCH);
Buttons buttons(&chipX, &chipY, PIN_BUTTONS);


void onAirconLCDClock()
{   
    aircon.onLCDClock();
}

void onAirconLCDClear()
{
    aircon.onLCDClear();
}

void onButtonPressed(ButtonID button)
{
    switch (button)
    {
        case NONE:
            break;
        case MAP:
            Keyboard.press(KEY_UP_ARROW);
            delay(200);
            Keyboard.release(KEY_UP_ARROW);
            break;
        case MENU:
            Keyboard.press(KEY_DOWN_ARROW);
            delay(200);
            Keyboard.release(KEY_DOWN_ARROW);
            break;
        case LOCATION:
            Keyboard.press(KEY_RIGHT_ARROW);
            delay(200);
            Keyboard.release(KEY_RIGHT_ARROW);
            break;
        case INFORMATION:
            Keyboard.press(KEY_LEFT_GUI);
            delay(200);
            Keyboard.release(KEY_LEFT_GUI);
            break;
        case AUDIO:
            Keyboard.press(KEY_RETURN);
            delay(200);
            Keyboard.release(KEY_RETURN);
            break;
        case MONITOR:
            Keyboard.print(KEY_LEFT_ARROW);
            delay(200);
            Keyboard.release(KEY_LEFT_ARROW);
            break;
        case AIRCON:
            Keyboard.println("Aircon");
            break;
    }
    Serial.print("Button ");
    Serial.print(button);
    Serial.println(" pressed");
}

void onButtonReleased(ButtonID button)
{
    Serial.print("Button ");
    Serial.print(button);
    Serial.println(" released");
}

void onScreenTouched(GridPoint point)
{
    AbsMouse.move(36.66 + point.x * 22, 26.66 + (8 - point.y) * 18);
    AbsMouse.press();
    Serial.print("Screen touched at ");
    Serial.print(point.x);
    Serial.print("x");
    Serial.println(point.y);
}

void onScreenExited()
{
    AbsMouse.release();
    Serial.println("Screen touch exited");
}

void setup() 
{
    Serial.begin(115200);

    attachInterrupt(digitalPinToInterrupt(PIN_CLOCK), onAirconLCDClock, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_CLEAR), onAirconLCDClear, RISING);

    AbsMouse.init(320, 240);

    touch.setTouchCallback(onScreenTouched);
    touch.setExitCallback(onScreenExited);

    buttons.setButtonPressCallback(onButtonPressed);
    buttons.setButtonReleaseCallback(onButtonReleased);

}

void loop()
{   
    buttons.update();
    touch.update();
}