/**************************

Protothreading is timed mutlitasking

**************************/

//#include <time.h>
//#include <millis.h>

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
