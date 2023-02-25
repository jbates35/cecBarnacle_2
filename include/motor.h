#pragma once
#include <Arduino.h>

enum class mtrDir
{
    REVERSE,
    FORWARD,
    BRAKE
};

class BMotor
{
public:
    BMotor();

    void init(int PINCW, int PINCCW, int PINPWM);
    void run();

    void brake();

    void turnOn();
    void turnOff();

    void setOffset(float multi);

    void setDirection(mtrDir thisDir);
    mtrDir getDirection();

    void setMultiplier(float thisMulti);
    float getMultiplier();

    bool isOn();

    void setPwmVal(int val);
    int getPwmVal();

private:
    int currentPWMVal;
    bool motorIsOn;
    mtrDir dir;
    float multi;
    int startTimer;

    int cwPin, ccwPin, pwmPin;

};