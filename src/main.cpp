#include <Arduino.h>
#include "motor.h"

BMotor motorL;
BMotor motorR;

namespace mtrPins
{
  const int MOTOR1_CW = 22;
  const int MOTOR1_CCW = 23;
  const int MOTOR1_PWM = 2;

  const int MOTOR2_CW = 52;
  const int MOTOR2_CCW = 53;
  const int MOTOR2_PWM = 46;
}

void setup() {
  // put your setup code here, to run once:
  motorL.init(mtrPins::MOTOR1_CW, mtrPins::MOTOR1_CCW, mtrPins::MOTOR1_PWM);
  motorL.init(mtrPins::MOTOR2_CW, mtrPins::MOTOR2_CCW, mtrPins::MOTOR2_PWM);

  motorL.turnOn();
  motorL.setDirection(mtrDir::FORWARD);
  
}

void loop() {
  

}