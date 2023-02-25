#include <Arduino.h>
#include "motor.h"

BMotor motorL;
BMotor motorR;

int dir;

enum 
{
  REVERSE,
  FORWARD,
  LEFT,
  RIGHT,
  BRAKE
};

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
  //put your setup code here, to run once:

  pinMode(mtrPins::MOTOR1_CW, OUTPUT);
  pinMode(mtrPins::MOTOR1_CCW, OUTPUT);
  pinMode(mtrPins::MOTOR1_PWM, OUTPUT);
  pinMode(mtrPins::MOTOR2_CW, OUTPUT);
  pinMode(mtrPins::MOTOR2_CCW, OUTPUT);
  pinMode(mtrPins::MOTOR2_PWM, OUTPUT);

  analogWrite(mtrPins::MOTOR1_PWM, 150);
  analogWrite(mtrPins::MOTOR2_PWM, 150);
  dir==BRAKE;

}

void loop() {

  switch(dir)
  {
    case FORWARD:
      digitalWrite(mtrPins::MOTOR1_CW, HIGH);
      digitalWrite(mtrPins::MOTOR1_CCW,LOW);
      digitalWrite(mtrPins::MOTOR2_CW, HIGH);
      digitalWrite(mtrPins::MOTOR2_CCW,LOW);


    break;
    case REVERSE:
      digitalWrite(mtrPins::MOTOR1_CW, LOW);
      digitalWrite(mtrPins::MOTOR1_CCW,HIGH);
      digitalWrite(mtrPins::MOTOR2_CW, LOW);
      digitalWrite(mtrPins::MOTOR2_CCW,HIGH);
      break;


    break;
    case LEFT:
      digitalWrite(mtrPins::MOTOR1_CW, LOW);
      digitalWrite(mtrPins::MOTOR1_CCW,HIGH);
      digitalWrite(mtrPins::MOTOR2_CW, HIGH);
      digitalWrite(mtrPins::MOTOR2_CCW,LOW);
      break;



    break;
    case RIGHT:
      digitalWrite(mtrPins::MOTOR1_CW, HIGH);
      digitalWrite(mtrPins::MOTOR1_CCW,LOW);
      digitalWrite(mtrPins::MOTOR2_CW, LOW);
      digitalWrite(mtrPins::MOTOR2_CCW,HIGH);
      break;


    break;
    case BRAKE:
      digitalWrite(mtrPins::MOTOR1_CW, LOW);
      digitalWrite(mtrPins::MOTOR1_CCW,LOW);
      digitalWrite(mtrPins::MOTOR2_CW, LOW);
      digitalWrite(mtrPins::MOTOR2_CCW,LOW);
      break;

    default:
    break;

  }

  
}

