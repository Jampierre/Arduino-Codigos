#include "SIM900.h"
#include <SoftwareSerial.h>
//Carrega a biblioteca SMS
#include "sms.h"

void setup() {

  SerialUSB.begin(115200);

  Serial.begin(115200);

  Serial1.begin(115200);

  while ( !SerialUSB );

  SerialUSB.println("Serial Test...");

}

void loop() {

  Serial.println("Hello");

  Serial1.println("Hello");

  SerialUSB.println("Hello");

  delay(1000);

}
