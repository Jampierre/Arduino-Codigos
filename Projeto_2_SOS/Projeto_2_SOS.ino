// Projeto 2 - S.O.S
int ledPin = 10;

void setup(){
  pinMode(ledPin, OUTPUT); // define o pino como saida 
}

void loop(){ // executa repetidas vezes
  for(int x=0; x<3; x++){ // roda 3x
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150);                // espera 150ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);
  }
  
  delay(100); // espera 100ms para marcar o intervalo entre as letras
  
  for(int x=0; x<3; x++){ // roda 3x
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(400);               
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);
  }
  
  delay(100);
  
  for(int x=0; x<3; x++){ // roda 3x
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150);                // espera 150ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);
  }
  
  delay(5000);
}
