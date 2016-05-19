/**
 * shutUpPigeon.h - Library for shutting up a pigon.
 */
#ifndef shutUpPigeon_h_
#define shutUpPigeon_h_
#include "Arduino.h"

class shutUpPigeon {
  public:
    shutUpPigeon(char start, char end);

  public:
    void init(void);
    void canSing(void);
    void hello(void);
    void shutUp(void);

  private:
    int _status;
}

#endif
