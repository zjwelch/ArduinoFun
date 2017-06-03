/**************************

Protothreading is timed mutlitasking

**************************/


#include <Arduino.h>
#include <time.h>
//#include <Wire.h>


class protoThread {

  private:
  
    unsigned long timerLength;
    unsigned long millisMax;
    unsigned long startTime;
    unsigned long endTime;
    unsigned long rolledTime;
    
  public:
    
    void setTimer( unsigned long timerLength );

    bool checkTimer();
    void resetTimer();
    protoThread();
    
};

