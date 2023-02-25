#include <Arduino.h>
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

// Global declarations
const int RECV_PIN = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Enable the IR receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  IrReceiver.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    // Decodes the pressed button into the functionality you want it to have
    if (IrReceiver.decodedIRData.decodedRawData != 0)
    {
      press_button(IrReceiver.decodedIRData.decodedRawData);
    }
    // implementing millis()
    delay(200);
    IrReceiver.resume();
  }
}

void press_button(uint32_t button_pressed) {
 switch (button_pressed) {
  case UP:
    // execute UP logic
    Serial.println("UP PRESSED");
  break;
  case DOWN:
    // execute DOWN logic
    Serial.println("DOWN PRESSED");
  break;
  case LEFT:
    // execute LEFT logic
    Serial.println("LEFT PRESSED");
  break;
  case RIGHT:
   // execute RIGHT logic
   Serial.println("RIGHT PRESSED");
  break;
  case OK:
   // execute OK logic
   Serial.println("OK PRESSED");
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
}