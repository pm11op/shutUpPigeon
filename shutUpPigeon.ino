#include <Adafruit_SleepyDog.h>
#include <ShutUpPigeon.h>
ShutUpPigeon piyo;
int pin_servo = 9;
int default_servo_angle = 46;  // 初期位置合わせ
int unit_angle = 18; // 必要角度
int status = 0;

void setup () {
  // init RTC
  Serial.begin(9600);
  piyo.init("6:55", "21:45");
//  piyo.init("23:00", "17:48");
//  piyo.init("23:55", "15:50");
  piyo.setServo(pin_servo, default_servo_angle, unit_angle);

}
void loop() {
  if (piyo.canSing()) {
    piyo.hello();
  } else {
    piyo.shutUp();
  }
  /*
  if (status == 0) {
    piyo.hello();
    status = 1;
  } else {
    piyo.shutUp();
    status = 0;
  }
  */
  
  // now sleeping...
  delay(1000); // necessary
  int sleepMS = Watchdog.sleep();
  Serial.print("I'm awake now!  I slept for ");
  Serial.print(sleepMS, DEC);
  Serial.println("");
}
