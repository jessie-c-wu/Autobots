#include "Motor.h"

Motor frontMotor(13,12);
Motor backMotor(11,10);
Motor leftMotor(9,8);
Motor rightMotor(7,6);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  forward();
  delay(500);
  backward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  toNW();
  delay(500);
  toSE();
  delay(500);
  toNE();
  delay(500);
  toSW();
  delay(500);
  clockwise();
  delay(500);
  counterclockwise();
  delay(500);
  brake();
  delay(500);
}

void forward() {
  leftMotor.moveForwards();
  rightMotor.moveForwards();
  frontMotor.brake();
  backMotor.brake();
}

void backward() {
  leftMotor.moveBackwards();
  rightMotor.moveBackwards();
  frontMotor.brake();
  backMotor.brake();
}

void left() {
  leftMotor.brake();
  rightMotor.brake();
  frontMotor.moveBackwards();
  backMotor.moveBackwards();
}

void right() {
  leftMotor.brake();
  rightMotor.brake();
  frontMotor.moveForwards();
  backMotor.moveForwards();
}

void toNW(){
  leftMotor.moveForwards();
  rightMotor.moveForwards();
  frontMotor.moveBackwards();
  backMotor.moveBackwards();
}

//note: SE is reserved
void toSE(){
  leftMotor.moveBackwards();
  rightMotor.moveBackwards();
  frontMotor.moveForwards();
  backMotor.moveForwards();
}

void toNE(){
  leftMotor.moveForwards();
  rightMotor.moveForwards();
  frontMotor.moveForwards();
  backMotor.moveForwards();
}

void toSW(){
  leftMotor.moveBackwards();
  rightMotor.moveBackwards();
  frontMotor.moveForwards();
  backMotor.moveBackwards();
}

void clockwise(){
  leftMotor.moveForwards();
  rightMotor.moveBackwards();
  frontMotor.moveForwards();
  backMotor.moveBackwards();
}

void counterclockwise(){
  leftMotor.moveBackwards();
  rightMotor.moveForwards();
  frontMotor.moveBackwards();
  backMotor.moveForwards();
}

void brake(){
  leftMotor.brake();
  rightMotor.brake();
  frontMotor.brake();
  backMotor.brake();
}

