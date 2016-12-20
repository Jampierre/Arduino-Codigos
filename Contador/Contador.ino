int i = .000;

void setup() {
  // put your setup code here, to run once:
  //Serial connection.
     Serial.begin(9600);

}

void loop() {
  Serial.println(i);
  i++;

  Serial.println(i/5);
  delay(5000);
}
