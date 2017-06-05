#include ZJ_Motion.h

void PIR_Sensor(){
  pinMode( PIR_INPUT_PIN, INPUT );
  //input = analogRead(PIR_INPUT_PIN);
  pinState = LOW;
  bool activity = false;
}

bool motionDetected() {
  pinState = digitalRead( PIR_INTPUT_PIN );
  if( pinState = HIGH ) {
    return true;
  } 
  return false;
}
