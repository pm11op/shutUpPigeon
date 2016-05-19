/**
 * ShutUpPigeon.h - Library for shutting up a pigon.
 */

#ifndef ShutUpPigeon_h
#define ShutUpPigeon_h
#include "Arduino.h"
#include <Servo.h>

class ShutUpPigeon {
  public:
    ShutUpPigeon(void);
    void init(char start[], char end[]);
    void setServo(int pin, int default_angle, int unit_angle);
    bool canSing(void);
    void hello(void);
    void shutUp(void);
    void moveServo(int angle);
    
  private:
    int _status, _start, _end, _sing_servo_angle, _shutup_servo_angle,
      _current_servo_angle;
    int _getTime(char time[]);
    int _getNow(void);
    Servo _servo;
};

#endif
