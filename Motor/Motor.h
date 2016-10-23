/*
  Motor.h - Library for Motors.
  Darwin Huang. 
  10/23/16
*/


#ifndef Motor_h
#define Motor_h

class Motor
{
  public:
    Motor(int Plus_pin, int Minus_pin);
    void moveForwards();
    void moveBackwards();
    void brake();
    void move(int power);

  private:
    int plus_pin;
    int minus_pin;    
};

#endif
