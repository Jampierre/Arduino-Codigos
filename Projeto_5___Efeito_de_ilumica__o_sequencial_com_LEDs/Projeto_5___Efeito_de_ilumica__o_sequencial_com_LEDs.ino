// Projeto 5 – Efeito de iluminação sequencial com LEDs

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // cria um array para os pinos dos LEDs
int ledDelay(65); // intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

void setup(){
 for(int x=0; x<10; x++){  //define todos os pinos como saida
  pinMode(ledPin[x], OUTPUT);
 } 
 changeTime = millis();
}

void loop(){
 if((millis() - changeTime) > ledDelay){ //verifica se ja transcorreram ledDelay ms desde a ultima alteraçao
  changeLED();
  changeTime = millis();
 } 
}

void changeLED(){
 for(int x=0; x<10; x++){ //apaga todos os LEDs
  digitalWrite(ledPin[x], LOW);
 } 
 digitalWrite(ledPin[currentLED], HIGH); //acende o LED atual
 currentLED += direction; //incrementa de acordo com o valor de direction
 // altera a direcao se tivermos atingido o fim
 if(currentLED == 9) {
  direction = -1; 
 }
 if(currentLED == 0) {
   direction = 1; 
 }
}
