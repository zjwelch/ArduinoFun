#include "ZJ_ProtoThread.h"

protoThread::protoThread(){
  //millis() will eventually rollover back to zero. This is to account for that
  millisMax = 2147483647;
  rolledTime = 0;
}

void protoThread::setTimer( unsigned long timer ) {
  timerLength = timer;
  resetTimer();
  
}

void protoThread::resetTimer( void ){

  unsigned long rollTime = 0;
  startTime = millis();
  
  //if the requested timer length saddles the rollover
  if( ( millisMax - startTime ) <= timerLength ){
    rollTime = ( millisMax - startTime );
  } else {
      endTime = startTime + timerLength;
      rolledTime = 0;
  }
  
  if ( rollTime != 0 ){

  
    //store the amount before the roll and set the timer for after the roll
    rolledTime = rollTime;
    endTime = ( timerLength - rollTime );


  }
  
  return;
}

bool protoThread::checkTimer( void ){
  unsigned long currTime = millis();
  
  if( currTime >= endTime ){
    resetTimer();
    return true;
    
  } else if( currTime < endTime ){
      return false;
    
    } else if (rolledTime > 0){
      if( (rolledTime + currTime) >= timerLength ){   
        resetTimer();
        return true;
      } else {
        resetTimer();
        return false;
      }    
  } else {
    resetTimer();
    return false;
  }
  return false;
}
