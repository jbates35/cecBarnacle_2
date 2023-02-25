#include <Arduino.h>
#include <IRremote.h>


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
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(100);
    IrReceiver.resume();
  }
}