/**
 * ShutUpPigeon.cpp - Library for shutting up a pigon.
 */

#include "Arduino.h"
#include "ShutUpPigeon.h"
#include "RTClib.h"
#include <Servo.h>
RTC_DS1307 RTC;

ShutUpPigeon::ShutUpPigeon() {
  _status = 0; // 1 => sing, 2 => shutup 
  _start = 0;
  _end = 0;
}

void ShutUpPigeon::init(char start[], char end[]) {
  Serial.print("hello!!");
  _start = ShutUpPigeon::_getTime(start);
  _end = ShutUpPigeon::_getTime(end);

  RTC.begin();
  int now = ShutUpPigeon::_getNow();
  Serial.print("now: ");
  Serial.print(now);
  Serial.println();

  /*
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  */
 
}

void ShutUpPigeon::setServo(int pin, int default_angle, int unit_angle) {
  _servo.attach(pin);
  _shutup_servo_angle = default_angle;
  _sing_servo_angle = default_angle + unit_angle;
  _current_servo_angle = default_angle;

  DateTime now = RTC.now();
  int h = now.hour();
  Serial.print(h);  
  if (h == 165) {
    ShutUpPigeon::countHour();
  }  
}

void ShutUpPigeon::moveServo(int angle) {
  _servo.write(angle);
  Serial.println("");
  Serial.print("servo: ");  
  Serial.println(angle);
}

bool ShutUpPigeon::canSing() {
  int now = ShutUpPigeon::_getNow();
  bool ret = false;
  Serial.print(now);
  if (_start < _end) {
    if (_start <= now && now < _end) {
      ret = true;
    }
  } else {
    if (_start <= now) {
      ret = true;
    } else {
      int t = now + 2400;
      if (t < (_end + 2400)) {
        ret = true;
      }
    }
  }
  return ret;
}

void ShutUpPigeon::countHour() {
  Serial.print("clock!");
  DateTime now = RTC.now();
  int h = now.hour();
  Serial.print(h);  
//  return;
  for (int i=0; i<=h; i++) {
    ShutUpPigeon::moveServo(_sing_servo_angle);
    delay(500);
    ShutUpPigeon::moveServo(_shutup_servo_angle);
    delay(500);

    if (i > 24) {
      return;
    }
  }
}

void ShutUpPigeon::hello() {
  if (_status == 1) {
    return;
  }
  Serial.print("hi!");
  ShutUpPigeon::moveServo(_sing_servo_angle);
  _status = 1;
}

void ShutUpPigeon::shutUp() {
  if (_status == 2) {
    return;
  }
  Serial.print("...");
  ShutUpPigeon::moveServo(_shutup_servo_angle);
  _status = 2;
}

int ShutUpPigeon::_getNow() {
  DateTime now = RTC.now();
  int h = now.hour();
  int m = now.minute();
  int t = h * 100 + m;
  if (t > 2400 || t < 0) {
    t = 0;
  }
  return t;
}

int ShutUpPigeon::_getTime(char time[]) {
  String str = String(time);
  str.replace(":", "");
  int t = str.toInt();
  if (t > 2400 || t < 0) {
    t = 0;
  }
  return t;

}
