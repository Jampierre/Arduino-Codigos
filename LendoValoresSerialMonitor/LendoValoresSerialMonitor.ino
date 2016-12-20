#include <SoftwareSerial.h>
char num1[200];
char num2[200];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Testando GSM Shield...");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Valor 1:");
  readSerial(num1);
  Serial.print("Valor 2:");
  readSerial(num2);

  Serial.println(num1);
  Serial.println(num2);
}

/*
  Read input serial
 */
int readSerial(char result[]) {
  Serial.print("readSerial");
  int i = 0;
  while (1) {
    while (Serial.available() > 0) {
      char inChar = Serial.read();
      if (inChar == '\n') {
        result[i] = '\0';
        Serial.flush();
        return 0;
      }
      if (inChar != '\r') {
        result[i] = inChar;
        i++;
      }
    }
  }
}
