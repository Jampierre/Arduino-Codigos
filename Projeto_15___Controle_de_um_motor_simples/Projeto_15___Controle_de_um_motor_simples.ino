//Projeto 15 - Controle de um motor simples

int potPin = 0;  //Analogico no 0, conectado ao potenciometro
int transistorPin = 9;  //Pino PWM 9 conectado a base do transistor
int potValue = 0;  //valor retornado do potenciometro

void setup() {
  // put your setup code here, to run once:
  // define o pino do transistor como saida:
  pinMode(transistorPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  //le o potenciometro, converte para o intervalo de 0 a 255:
  potValue = analogRead(potPin) / 4;
  //utiliza isso para controlar o transistor:
  analogWrite(transistorPin, potValue);
}
