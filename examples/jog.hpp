#include <ServoEasing.hpp>
#include <M5Atom.h>

ServoEasing g_servo;
bool g_flag;
bool g_pre_isMoving;
bool g_isMoving;

void setup() {
  M5.begin(true, false, true);

  g_servo.attach(25, 
                 90, 
                 DEFAULT_MICROSECONDS_FOR_0_DEGREE,
                 DEFAULT_MICROSECONDS_FOR_180_DEGREE);
  g_isMoving = false;
  g_pre_isMoving = g_servo.isMoving();
}

void loop() {
  M5.update();
  if(!g_isMoving && M5.Btn.wasPressed()) {
    Serial.println("START");
    int target = 0;
    if(g_flag) {
      target = 0;
    }
    else {
      target = 180;
    }
    Serial.printf("MOVE %d\n", target);
    g_servo.startEaseTo(target, 45);
    g_isMoving = true;
  }
  if(g_isMoving && 
     (M5.Btn.wasReleased() || 
      (g_pre_isMoving && !g_servo.isMoving())
     )) {
    g_servo.stop();

    Serial.printf("END: currentAngle=%d\n",g_servo.getCurrentAngle());
    g_flag = !g_flag;
    g_isMoving = false;
  }
  g_pre_isMoving = g_servo.isMoving();
  delay(10);
}

