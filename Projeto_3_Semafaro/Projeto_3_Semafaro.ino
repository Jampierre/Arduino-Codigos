// Projeto 3 - Semafaro

int ledDelay = 5000; // espera entre as alterações
int redPin = 10;
int yellowPin = 9; 
int greenPin = 8;

void setup() { 
  pinMode(redPin, OUTPUT); 
  pinMode(yellowPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
}

void loop(){
 digitalWrite(redPin, HIGH);
 delay(ledDelay);
 
 digitalWrite(redPin, LOW);
 digitalWrite(greenPin, HIGH);
 delay(ledDelay);
 
 digitalWrite(greenPin, LOW); 
 digitalWrite(yellowPin, HIGH);
 delay(2000);
 
 digitalWrite(yellowPin, LOW);
}
