#include <QTRSensors.h>

//TODO testar invertido 
// 5 sensores, time-out 2000, sem pino de LED
QTRSensorsRC qtr((unsigned char[]) {2, 1, 5, 4, 3}, 5, 2000, QTR_NO_EMITTER_PIN);

// Definição de variáveis
unsigned int sensors[5]; // Matriz para armazenar valores dos sensores

//TODO destar invertido

//----MOTOR A direito ----//
int inA1 = 2; // Pinagem para a PONTE-H
int inA2 = 4;
int velocidadeA = 3;

//----MOTOR B----//
int inB1 = 6;
int inB2 = 7;
int velocidadeB = 5;

int last_proportional;
int integral;

// Executado na inicialização do Arduino
void setup() {
  Serial.begin(9600);        // Inicializa a comunicação serial
  set_motors(0, 0); // Enquanto espera, motores permanecem parados

  // Auto-calibração: gira para a direita e depois esquerda e volta ao início
  // calibrando os sensores
  unsigned int counter; // usado como um simples contador
  for (counter = 0; counter < 80; counter++) {
    if (counter < 20 || counter >= 60) {
      set_motors(50, -50); // Gira para a direita
    }
    else {
      set_motors(-50, 50); // Gira para a esquerda
    }
    // Esta função armazena um conjunto de leituras dos sensores, e mantém
    // informações sobre o máximo e mínimo valores encontrados
    qtr.calibrate();
    // Desde que contamos até 80, o total do tempo de calibração
    // será de 80 * 10 = 800 ms
    delay(10);
  }
  set_motors(0, 0); // Garante motores parados após o processo
  // de calibração
}


// Esta é a função principal, onde o código inicia. Todo programa Arduino
// deve ter uma função loop() definida em algum lugar
void loop() {
  // Obtém a posição da linha
  // Aqui não estamos interessados nos valores individuais de cada sensor
  unsigned int position = qtr.readLine(sensors);

  // O termo proporcional deve ser 0 quando estamos na linha
  int proportional = ((int)position) - 2000;

  // Calcula o termo derivativo (mudança) e o termo integral (soma)
  // da posição
  int derivative = proportional - last_proportional;
  integral += proportional;

  // Lembrando a ultima posição
  last_proportional = proportional;

  // Calcula a diferença entre o aranjo de potência dos dois motores
  // m1 - m2. Se for um número positivo, o robot irá virar para a
  // direita. Se for um número negativo, o robot irá virar para a esquerda
  // e a magnetude dos números determinam a agudez com que fará as curvas/giros
  int power_difference = proportional / 10 + integral / 10000 + derivative * 3 / 2;

  // Calcula a configuração atual dos motores.  Nunca vamos configurar
  // um motor com valor negativo
  const int max = 180;
  if (power_difference > max)
    power_difference = max;
  if (power_difference < -max)
    power_difference = -max;
  if (power_difference < 0)
    set_motors(max + power_difference, max);
  else
    set_motors(max, max - power_difference);
}

// Acionamento dos motores
void set_motors(int left_speed, int right_speed) {
  if (right_speed >= 0 && left_speed >= 0) {
    analogWrite(inA1, LOW);
    analogWrite(inA2, HIGH);
    
    analogWrite(inB1, LOW);
    analogWrite(inB2, HIGH);
    
    analogWrite(velocidadeA, right_speed);
    analogWrite(velocidadeB, left_speed);
  }
  if (right_speed >= 0 && left_speed < 0) {
    left_speed = -left_speed;
    analogWrite(inA1, LOW);
    analogWrite(inA2, HIGH);

    analogWrite(inB1, HIGH);
    analogWrite(inB2, LOW);
    
    analogWrite(velocidadeA, right_speed);
    analogWrite(velocidadeB, left_speed);
    
  }
  if (right_speed < 0 && left_speed >= 0) {
    right_speed = -right_speed;
    analogWrite(inA1, HIGH);
    analogWrite(inA2, LOW);
    
    analogWrite(inB1, LOW);
    analogWrite(inB2, HIGH);

    analogWrite(velocidadeA, right_speed);
    analogWrite(velocidadeB, left_speed);
  }
}
