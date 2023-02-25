#include "motor.h"

BMotor::BMotor()
{

}

void BMotor::init(int PINCW, int PINCCW, int PINPWM)
{
    cwPin = PINCW;
    ccwPin = PINCCW;
    pwmPin = PINPWM;

    pinMode(PINCW, OUTPUT);
    pinMode(PINCCW, OUTPUT);
    pinMode(PINCW, OUTPUT);
    

    dir = mtrDir::FORWARD;
    currentPWMVal = 0;
    multi = 1;
    motorIsOn = true;

    digitalWrite(cwPin, HIGH);
    digitalWrite(ccwPin, LOW);
    analogWrite(PINCW, 0);    
}

void BMotor::run()
{
    switch(dir)
    {
        case mtrDir::BRAKE:
        {
            digitalWrite(cwPin, LOW);
            digitalWrite(ccwPin, LOW);  
            break;
        }

        case mtrDir::FORWARD:
        {
            digitalWrite(cwPin, HIGH);
            digitalWrite(ccwPin, LOW);
            break;
        }

        case mtrDir::REVERSE:
        {
            digitalWrite(cwPin, LOW);
            digitalWrite(ccwPin, HIGH);
            break;
        }

        default:
            break;
    }
    
    if(dir==mtrDir::BRAKE)
    {
        analogWrite(pwmPin, 0);
    }
    else
    {
        analogWrite(pwmPin, (int) currentPWMVal * multi);

    }
    
}

void BMotor::brake()
{
    dir = mtrDir::BRAKE;
}

void BMotor::turnOn()
{
    motorIsOn = true;
}

void BMotor::turnOff()
{
    motorIsOn = false;
}

void BMotor::setDirection(mtrDir thisDir)
{
    dir = thisDir;
}

mtrDir BMotor::getDirection()
{
    return dir;
}

void BMotor::setMultiplier(float thisMulti)
{
    multi = thisMulti;
}

float BMotor::getMultiplier()
{
    return multi;
}

bool BMotor::isOn()
{
    return motorIsOn;
}

void BMotor::setPwmVal(int val)
{
    currentPWMVal = val;
}

int BMotor::getPwmVal()
{
    return currentPWMVal;
}
