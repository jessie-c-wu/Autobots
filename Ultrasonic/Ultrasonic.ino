#include "Ultrasonic.h"

int ultrasonicLowThreshold = 5;
int ultrasonicHighThreshold = 10;

Ultrasonic ultrasonic1(4,5);
Ultrasonic ultrasonic2(6,7);
Ultrasonic ultrasonic3(8,9);
Ultrasonic ultrasonic4(10,11);
Ultrasonic ultrasonic5(12,13);

void setup() {
Serial.begin(9600);
}

bool ultrasonicWithinThreshold(Ultrasonic ultrasonic){
  int read = ultrasonic.Ranging(CM);
  if(read > ultrasonicLowThreshold && read < ultrasonicHighThreshold){
    return true;
  }
  return false;
}

bool ultrasonicFront(){
  return ultrasonicWithinThreshold(ultrasonic2) || ultrasonicWithinThreshold(ultrasonic3) || ultrasonicWithinThreshold(ultrasonic4);
}

bool ultrasonicLeft(){
  return ultrasonicWithinThreshold(ultrasonic1);
}

bool ultrasonicRight(){
  return ultrasonicWithinThreshold(ultrasonic5);
}

void printAllRawUltrasonicValues(){
  Serial.print(ultrasonic1.Ranging(CM));
  Serial.print("\t");
  Serial.print(ultrasonic2.Ranging(CM));
  Serial.print("\t");
  Serial.print(ultrasonic3.Ranging(CM));
  Serial.print("\t");
  Serial.print(ultrasonic4.Ranging(CM));
  Serial.print("\t");
  Serial.print(ultrasonic5.Ranging(CM));
  Serial.print("\t");
  Serial.println();
}

void printUltrasonicThresholds(){
  int inFront = ultrasonicFront();
  int inLeft = ultrasonicLeft();
  int inRight = ultrasonicRight();

  if(inFront){
     Serial.print("FRONT\t");
  }
  if(inLeft){
    Serial.print("LEFT\t");
  }
  if(inRight){
    Serial.print("RIGHT\t");
  }
  if(!inFront && !inLeft && !inRight){
    Serial.print("ALL GOOD");
  }
  Serial.println();
}

void loop()
{
  printUltrasonicThresholds();
  delay(100);
}




