//----MOTOR B----//
int IN1 = 2 ;
int IN2 = 4 ;
int velocidadeA = 5;

//----MOTOR A direito ----//
int IN3 = 6 ;
int IN4 = 7 ;
int velocidadeB = 3;

int sensor1, sensor2, sensor3, sensor4, sensor5;

//Deslocamento de calibração
int leftOffset = 0, smallLeftOffset = 0, centre = 0, smallRightOffset = 0, rightOffset = 0;

// Velocidade inicial e deslocamentos de rotação
int startSpeed = 70, rotate = 20;

// Limiar do sensor;
int threshold = 5;

// Velocidades iniciais dos motores esquerdos e direito
int left = startSpeed, right = startSpeed;

const int s1 = A2; //SENSOR DA ESQUERDA DA PONTA
const int s2 = A1;  // SEGUNDO SENSOR DA ESQUERDA
const int s3 = A5;  // SENSOR MEIO
const int s4 = A4;  // SEGUNDO SENSOR DA DIREITA
const int s5 = A3;  // SENSOR DA DIREITA DA PONTA

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(velocidadeA, OUTPUT);
  pinMode(velocidadeB, OUTPUT);

  //------ENTRADA DOS SENSORES-----------/
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

//  calibrate();

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
//  int var = 0;
//  int var1 = 0;
  //  readSensores();
  //  lerdistancia();
  //  if(cmMsec<15){
  //    var1 = 1;
  //  }

  //  Velocidade dos motores = 50
  left = startSpeed;
  right = startSpeed;

  sensor1 = analogRead(s1) + leftOffset;
  sensor2 = analogRead(s2) + smallLeftOffset;
  sensor3 = analogRead(s3);
  sensor4 = analogRead(s4) + smallRightOffset;
  sensor5 = analogRead(s5) + rightOffset;

  //vira a direita desligando um motor
  if (sensor1 > (sensor3 + threshold)) {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, right);
  }

  //curva suave para direita
  if (sensor2 > (sensor3 + threshold)){
    left = startSpeed + rotate;
    right = startSpeed - rotate;

    analogWrite(velocidadeA, left);
    analogWrite(velocidadeB, right);
  }

  if(sensor4 > (sensor2 + threshold)){
    left = startSpeed - rotate;
    right = startSpeed + rotate;
    analogWrite(velocidadeA, left);
    analogWrite(velocidadeB, right);
  }

  if(sensor5 > (sensor3 + threshold)){
    analogWrite(velocidadeA, left);
    analogWrite(velocidadeB, 0);
  }
}
