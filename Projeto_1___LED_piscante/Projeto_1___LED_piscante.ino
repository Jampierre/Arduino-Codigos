// Projeto 1 - LED piscante 
int ledPin = 10;
void setup() {
  pinMode(ledPin, OUTPUT); //Informara que a variavel sera uma saida
}
void loop() { 
  digitalWrite(ledPin, HIGH); //envia para o pino 5V
  delay(1000); 
  digitalWrite(ledPin, LOW);  //envia para o pino 0V
  delay(1000);
}
