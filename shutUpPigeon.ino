
/*
// #include <Wire.h>
#include "RTClib.h"
#include <Time.h>
 
RTC_DS1307 RTC;

#include <Servo.h>
Servo myservo;
int pin_servo = 9;
int default_servo_angle = 46;  // 初期位置合わせ
int unit_angle = 15; // 必要角度
int servo_angle = default_servo_angle;


#include <Adafruit_SleepyDog.h>
*/
#include <ShutUpPigeon.h>

//ShutUpPigeon piyo('7:00', '21:30');

void setup () {
  // init RTC
  Serial.begin(115200);
//  piyo.init();

  /* init Servo
  RTC.begin();
 
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
     RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  myservo.attach(pin_servo);
  delay(100);
  myservo.write(default_servo_angle);
  delay(100);
  */
}
void loop() {
  /*
  // Sleep
  if (piyo.canSing()) {
    piyo.hello();
  } else {
    piyo.shutUp();
  }
  delay(1000);
  int sleepMS = Watchdog.sleep();

  return;
  */
}

/*
void _loop () {
  int *ret;
  int hms[3];
  ret = timer(hms);
  Serial.println();

  delay(5000);
  if (hms[2] >= 10) {
//    return;  
  }
  servo_angle = servo_angle + unit_angle;
  // just toggle
  if (servo_angle > default_servo_angle + unit_angle) {
    servo_angle = default_servo_angle;
  }
  mv_servo(servo_angle);

}

int *timer(int *hms) {
    DateTime now = RTC.now();
 
    int h = now.hour();
    int m = now.minute();
    int s = now.second();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(h, DEC);
    Serial.print(':');
    Serial.print(m, DEC);
    Serial.print(':');
    Serial.print(s, DEC);
    Serial.println();

    hms[0] = h;
    hms[1] = m;
    hms[2] = s;
    return hms;
  }



void mv_servo(int angle) {
  Serial.println(angle);
  myservo.write(angle);
  Serial.println();
}
*/
