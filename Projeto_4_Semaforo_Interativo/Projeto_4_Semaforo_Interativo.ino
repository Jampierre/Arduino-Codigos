// Projeto 4 – Semáforo interativo

int carRed = 12;             // estabelece o semáforo para carros 
int carYellow = 11;
int carGreen = 10;
int pedRed = 9;             // estabelece o semáforo para pedestres 
int pedGreen = 8;
int button = 2;             // pino do botão
int crossTime = 5000;       // tempo para que os pedestres atravessem
unsigned long changeTime;   // tempo desde que o botão foi pressionado

void setup(){
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT); 
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT); // botão no pino 2 
  
  // acende a luz verde
  digitalWrite(carGreen, HIGH); 
  digitalWrite(pedRed, HIGH);
}

void loop(){
 int state = digitalRead(button);
 
 /* verifica se o botão foi pressionado e se transcorreram 5 segundos 
     desde a última vez que isso ocorreu */ 
 if (state == HIGH && (millis() - changeTime) > 5000) {
   // Chama a função para alterar as luzes
   changeLights();
 }
}

void changeLights() {
 digitalWrite(carGreen, LOW);
 digitalWrite(carYellow, HIGH);
 delay(1000);

 digitalWrite(carYellow, LOW);
 digitalWrite(carRed, HIGH);
 delay(2000); 
 
 digitalWrite(pedRed, LOW);
 digitalWrite(pedGreen, HIGH);
 delay(crossTime);
 
 // pisca o verde dos pedestres
 for (int x=0; x<10; x++) {
    digitalWrite(pedGreen, HIGH); 
    delay(250); 
    digitalWrite(pedGreen, LOW); 
    delay(250);
  }
  
 // acende o vermelho dos pedestres 
 digitalWrite(pedRed, HIGH); 
 delay(500);
 
 digitalWrite(carRed, LOW);  
 digitalWrite(carGreen, HIGH); 
 delay(1000);
 
 // registra o tempo desde a última alteração no semáforo 
 changeTime = millis();
 // depois retorna para o loop principal do programa
}
