#include <Servo.h> // Using servo library

Servo im_servo; // create servo object

int potPin= A0;
int val;

void setup() {
  im_servo.attach(9);
}

void loop() {
  val= analogRead(potPin);
  val= map (val, 0, 1023, 0, 180);
  im_servo.write(val);
  delay(15);
} 
