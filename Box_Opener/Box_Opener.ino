#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = 
char ssid[] = 
char pass[] = 

Servo i_servo;

BLYNK_WRITE(V5)
{
  i_servo.write(param.asInt());
}

void setup ()
{
  Blynk.begin(auth, ssid, pass);
  i_servo.attach(D9);
}

void loop()
{
  Blynk.run();
}
