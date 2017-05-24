/**************************

Protothreading is timed mutlitasking

**************************/

//#include <time.h>
//#include <millis.h>

/*
class protoThread {

  private:
  
    unsigned long timerLength;
    unsigned long millisMax;
    unsigned long startTime;
    unsigned long endTime;
    unsigned long rolledTime;
    
  public:
    
    void setTimer( unsigned long timerLength );
    boolean checkTimer();
    void resetTimer();
    protoThread();
    ~protoThread();
    
};
*/

//begin cpp
/*
void protoThread::protoThread( void ){

  //millis() will eventually rollover back to zero. This is to account for that
  unsigned long millisMax = 2147483647;
  unsigned long rolledTime = 0;

}

void protoThread::setTimer( unsigned long timer ) {

  timerLength = timer;
  resetTimer();
  
}

void protoThread::resetTimer( void ){

  startTime = millis();
  
  try {
  
    //if the requested timer length saddles the rollover
    if( ( millisMax - startTime ) >= timerLength ){
      throw ( millisMax - startTime );
    } else {
      endTime = startTime + timerLength;
      rolledTime = 0;
    }
  }  
  catch ( unsigned long rollTime ){
  
    //store the amount before the roll and set the timer for after the roll
    rolledTime = rollTime;
    endTime = ( timerLength - rollTime );
  
  }
  return;
}

boolean protoThread::check( void ){

  try {
    if( !( millisMax - startTime >= endTime ) ){
    
  } catch {
  }
  if(){
    protoThread::reset();
    return 1;
  } else {
    return 0;
  }
}

void protoThread::~setTimer( void ){
  
  timer.clear();
  startTime.clear();
  rolledTime.clear();
  millisMax.clear();
  
}

*/
