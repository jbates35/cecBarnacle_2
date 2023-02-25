#include <Arduino.h>

#include <Servo.h>

#include "motor.h"

BMotor motorL;
BMotor motorR;

// Global declarations
const int RECV_PIN = 3;
#define FAULT_LED 50
#define RUNNING_LED 51

#define SERVO_PIN 7
#define SERVO_UP 100
#define SERVO_DOWN 80

#include <IRremote.h>

// Decoding the hex values that the remote sends into readable user data
enum button {
 ONE         = 3125149440,
 TWO         = 3108437760,
 THREE       = 3091726080,
 UP          = 3877175040,
 DOWN        = 2907897600,
 LEFT        = 4144561920,
 RIGHT       = 2774204160,
 OK          = 3810328320,
 ASTERISK    = 3910598400,
 ZERO        = 3860463360,
 NUMBER_SIGN = 4061003520
};

// Creating enumarated object
button button_pressed;


int time, timePrev;

int dir;

bool isFault, isRunning;

Servo liftServo;

enum 
{
  REVERSE,
  FORWARD,
  MLEFT,
  MRIGHT,
  BRAKE
};

void press_button(uint32_t button_pressed);

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

  isFault=false;
  isRunning=false;


  // put your setup code here, to run once:
  Serial.begin(9600);
  // Enable the IR receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  IrReceiver.enableIRIn();

  //put your setup code here, to run once:
  pinMode(FAULT_LED, OUTPUT);
  pinMode(RUNNING_LED, OUTPUT);

  liftServo.attach(SERVO_PIN);

  pinMode(mtrPins::MOTOR1_CW, OUTPUT);
  pinMode(mtrPins::MOTOR1_CCW, OUTPUT);
  pinMode(mtrPins::MOTOR1_PWM, OUTPUT);
  pinMode(mtrPins::MOTOR2_CW, OUTPUT);
  pinMode(mtrPins::MOTOR2_CCW, OUTPUT);
  pinMode(mtrPins::MOTOR2_PWM, OUTPUT);

  analogWrite(mtrPins::MOTOR1_PWM, 150);
  analogWrite(mtrPins::MOTOR2_PWM, 150);

  digitalWrite(mtrPins::MOTOR1_CW, HIGH);
  digitalWrite(mtrPins::MOTOR1_CCW,LOW);
  digitalWrite(mtrPins::MOTOR2_CW, HIGH);
  digitalWrite(mtrPins::MOTOR2_CCW,LOW);
  
  dir=BRAKE;

  time=millis();
  timePrev = millis();

}

void loop() {

  if(isFault)
  {
    digitalWrite(FAULT_LED, HIGH);
  }
  else
  {
    digitalWrite(FAULT_LED, LOW);
  }

  if(dir==BRAKE)
  {
    digitalWrite(RUNNING_LED, LOW);
  } 
  else
  {
    digitalWrite(RUNNING_LED, HIGH);
  }

  if(millis()-timePrev >= 1000)
  {
    timePrev = millis();
    Serial.println("asdf");
  }


  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {  
    // Decodes the pressed button into the functionality you want it to have
    if (IrReceiver.decodedIRData.decodedRawData != 0)
    {
      press_button(IrReceiver.decodedIRData.decodedRawData);
    }
    // implementing millis()
    //delay(200);
    IrReceiver.resume();
  }
}



void press_button(uint32_t button_pressed) {
 switch (button_pressed) {
  case UP:
    // execute UP logic
    Serial.println("UP PRESSED");

    // Move forwards
    dir = FORWARD;

  break;
  case DOWN:
    // execute DOWN logic
    Serial.println("DOWN PRESSED");

    // Move backwards
    dir = REVERSE;
  break;
  case LEFT:
    // execute LEFT logic
    Serial.println("LEFT PRESSED");

    // Continuously turn left
    dir = MLEFT;
  break;
  case RIGHT:
   // execute RIGHT logic
   Serial.println("RIGHT PRESSED");

   // Continuously turn right
  dir = MRIGHT;
  break;
  case OK:
   // execute OK logic
   Serial.println("OK PRESSED");

   // Stop everything
   dir = BRAKE;
  break;
  case ASTERISK:
   // execute ASTERIK logic
   Serial.println("ASTERISK PRESSED");
  break;
  case ZERO:
   // execute ZERO logic
   Serial.println("ZERO PRESSED");
  break;
  case NUMBER_SIGN:
   // execute number sign logic
   Serial.println("NUMBER SIGN PRESSED");
  break;
  default:
   // for debugging
   Serial.println("Entering default state in button press");
  break;
 }

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
    case MRIGHT:
      digitalWrite(mtrPins::MOTOR1_CW, LOW);
      digitalWrite(mtrPins::MOTOR1_CCW,HIGH);
      digitalWrite(mtrPins::MOTOR2_CW, HIGH);
      digitalWrite(mtrPins::MOTOR2_CCW,LOW);
      break;



    break;
    case MLEFT:
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