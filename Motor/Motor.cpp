/*
  Motor.cpp - Library for Motors.
  Darwin Huang. 
  10/23/16
*/


#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int Plus_pin, int Minus_pin)
{
  pinMode(Plus_pin,OUTPUT);
  pinMode(Minus_pin,OUTPUT);
  plus_pin = Plus_pin;
  minus_pin = Minus_pin;
}

void Motor::moveForwards()
{
  digitalWrite(plus_pin, HIGH);
  digitalWrite(minus_pin, LOW);
}

void Motor::moveBackwards()
{
  digitalWrite(plus_pin, LOW);
  digitalWrite(minus_pin, HIGH);
}

void Motor::brake()
{
  digitalWrite(plus_pin, LOW);
  digitalWrite(minus_pin, LOW);
}

//from -255 to 255
void Motor::move(int power){
  if(power == 0){
    brake();
  }
  if(power > 255 || power < -255){
    return;
  }
  if(power > 0){
    analogWrite(plus_pin, power);
    digitalWrite(minus_pin, LOW);
  }
  else if(power < 0){
    digitalWrite(plus_pin, LOW);
    analogWrite(minus_pin, power * -1);
  }
}

