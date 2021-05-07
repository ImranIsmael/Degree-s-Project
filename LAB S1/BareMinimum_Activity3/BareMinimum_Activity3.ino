const int analog_ip = A0;
const int LED = 3;
int inputVal = 0;

void setup() {
  pinMode (LED, OUTPUT);
}

void loop() {
  inputVal = analogRead(analog_ip);
  analogWrite (LED, inputVal/4);
  delay(100);
}
