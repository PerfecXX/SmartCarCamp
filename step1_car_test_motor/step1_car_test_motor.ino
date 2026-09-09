#include "AFMotor_R4.h"

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int speed1 = 100;
int speed2 = 100;

void setup() {
  motor1.setSpeed(speed1);
  motor2.setSpeed(speed2);
}

void loop() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000);
}
