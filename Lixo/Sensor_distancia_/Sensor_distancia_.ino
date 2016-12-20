#include <NewPing.h>

#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define MAX_DISTANCE 200

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  unsigned int cm = DistanceSensor.ping_cm();


  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println("cm");

  delay(1000);
  // put your main code here, to run repeatedly:

}
