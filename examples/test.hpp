#include <ServoEasing.hpp>
#include <M5Atom.h>

ServoEasing g_servo;
bool g_flag;

void setup() {
  M5.begin(true, false, true);

  g_servo.attach(25, 
                 90, 
                 DEFAULT_MICROSECONDS_FOR_0_DEGREE,
                 DEFAULT_MICROSECONDS_FOR_180_DEGREE);
}

void loop() {
  M5.update();
  if(M5.Btn.wasPressed()) {
    Serial.println("START");
    int target = 0;
    if(g_flag) {
      target = 0;
    }
    else {
      target = 180;
    }
    Serial.printf("MOVE %d\n", target);
    g_servo.easeTo(target, 30);
    g_flag = !g_flag;
    Serial.println("END");
  }
}
