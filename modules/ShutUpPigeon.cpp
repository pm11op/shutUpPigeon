#include "Arduino.h"
#include "ShutUpPigeon.h"

ShutUpPigeon::ShutUpPigeon(char start, char end) {
  _start = start;
  _end = end;
  _status = 0;
}

void ShutUpPigeon::init() {
  Serial.println("hello!!");
}

void ShutUpPigeon::canSing() {

}

void ShutUpPigeon::hello() {

}

void ShutUpPigeon::shutUp() {

}
