#include <NewPing.h>

#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define MAX_DISTANCE 200

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#include <Ultrasonic.h>
//#define TRIGGER_PIN  8
//#define ECHO_PIN     9
//
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
//
float cmMsec, inMsec;
void lerdistancia() {
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);//CENTIMETROS
}


long Distancia = 0.0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //    unsigned int cm = DistanceSensor.ping_cm();
  //    Serial.print("Distance 1: ");
  //    Serial.print(cm);
  //    Serial.println("cm");

  //  lerdistancia();
  //  Serial.print("Distance 2: ");
  //  Serial.print(cmMsec);
  //  Serial.println("cm");
  //    delay(1000);

  medirDistancia();
}

void medirDistancia() {
  digitalWrite(TRIGGER_PIN, LOW);
  delay(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delay(10);
  digitalWrite(TRIGGER_PIN, LOW);
  unsigned long Du = pulseIn(ECHO_PIN, HIGH);
  delay(4);
  if (Du < 1450) {
    Distancia = (Du / 58.0);
    Serial.print("Distance 3: ");
    Serial.print(Distancia);
    Serial.println("cm");
  }

}

