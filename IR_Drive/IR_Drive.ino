#define inPin0 0
#define inPin1 1
#define inPin2 2
#define inPin3 3
int IR_FOUND;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  IR_FOUND = 0; 
}

void test_fb() {
  forward();
  delay(5000);
  FB_brake();
  delay(5000);
  backwards();
  delay(5000);
  FB_brake();
  delay(5000);
}

void test_lr() {
  right();
  delay(5000);
  LR_brake();
  delay(5000);
  left();
  delay(5000);
  LR_brake();
  delay(5000);
}

void forward() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void backwards() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void FB_brake() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

void left() {
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
}

void right() {
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void LR_brake() {
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
}

void loop() {
  digitalWrite(4, HIGH); 
  int pinRead0 = analogRead(inPin0);
  int pinRead1 = analogRead(inPin1);
  int pinRead2 = analogRead(inPin2);
  int pinRead3 = analogRead(inPin3);
  if (pinRead3 > 50 || pinRead2 > 50 || pinRead1 > 50 || pinRead0 > 50){
     IR_FOUND = 1;
  }
  else {
    IR_FOUND = 0;
  }
  forward();
  Serial.print("IR FOUND? ");
  Serial.print(IR_FOUND);
  Serial.print("\t IR Sensor 1: ");
  Serial.print(pinRead0);
  Serial.print("\t IR Sensor 2: ");
  Serial.print(pinRead1);
  Serial.print("\t IR Sensor 3: ");
  Serial.print(pinRead2);
  Serial.print("\t IR Sensor 4: ");
  Serial.print(pinRead3);
  Serial.println(); 
  if (IR_FOUND == 1) {
    FB_brake();
    delay(500);
    if (pinRead0 > pinRead1) {
      right();
    }
    if (pinRead3 > pinRead2) {
      left();
    }
    //else{
    //  LR_brake();
    //}
  }
} 

