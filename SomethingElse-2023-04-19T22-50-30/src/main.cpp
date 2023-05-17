/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Apr 19 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rightmotor           motor         1               
// leftmotor            motor         2               
// Inertial             inertial      3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

struct tune {
  float kp;
  float kd;
  float dt;
} drivePid={1,0,20}, turnPid={1,0,20};

float preverror = 0;
float PD(struct tune t, float error) {
  float p = error * t.kp;
  float d = (error - preverror) / t.dt;

  preverror= error;
  wait(t.dt, msec);
  return p+d;
}

void move(int dist) {
  rightmotor.setPosition(0, degrees);

  while(abs(dist - (int)rightmotor.position(degrees)) > 3) {
    float speed = PD(drivePid, dist - rightmotor.position(degrees));

    rightmotor.setVelocity(speed, percent);
    leftmotor.setVelocity(speed, percent);

    rightmotor.spin(forward);
    leftmotor.spin(forward);
  }

  rightmotor.stop();
  leftmotor.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  move(2000);
  move(-2000);
}