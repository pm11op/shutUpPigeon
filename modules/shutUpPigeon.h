/**
 * ShutUpPigeon.h - Library for shutting up a pigon.
 */

#ifndef ShutUpPigeon_h
#define ShutUpPigeon_h
#include "Arduino.h"

class ShutUpPigeon {
  public:
    ShutUpPigeon(void);
    void init(char start[], char end[]);
    bool canSing(void);
    void hello(void);
    void shutUp(void);
    
  private:
    int _status;
    int _start;
    int _end;
    int _getTime(char time[]);
    int _getNow(void);
};

#endif
