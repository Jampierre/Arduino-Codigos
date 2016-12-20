//  Programa: Motor Shield com sensor TCRT5000
//
//  Created by Jampierre Vieira Rocha on 4/11/16.
//  Copyright © 2016 Jampierre Vieira Rocha. All rights reserved.


#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define MAX_DISTANCE 200

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//Motor A
int ENA = 3; // Output pwm
int IN1 = 2;
int IN2 = 4;

//Motor B
int ENB = 5; // Output pwm
int IN3 = 6;
int IN4 = 7;

int sensor1, sensor2, sensor3;

// Deslocamentos de calibração
int leftOffset = 0, rightOffset = 0, centre = 0;

// Velocidade inicial e deslocamentos de rotação
int startSpeed = 50, rotate = 40;

// Limiar do sensor;
int threshold = 5;

// Velocidades iniciais dos motores esquerdos e direito
int left = startSpeed, right = startSpeed;

// Rotina de calibração do sensor
void calibrate(){
  // Executa 10x para obter uma media
  for(int x = 0; x < 10; x++){
    delay(100);
    sensor1 = analogRead(2);
    sensor2 = analogRead(5);
    sensor3 = analogRead(3);
    leftOffset = leftOffset + sensor1;
    centre = centre + sensor2;
    rightOffset = rightOffset + sensor3;
    delay(100);
  }

  //Obtem a media de cada sensor
  leftOffset = leftOffset / 10;
  rightOffset = rightOffset / 10;
  centre = centre / 10;

  Serial.print("leftOffset : ");
  Serial.println(leftOffset);
  Serial.print("rightOffset : ");
  Serial.println(rightOffset);
  Serial.print("centre : ");
  Serial.println(centre);

  //Calcula os deslocamentos para os sensores esquerdos e direito
  leftOffset = centre - leftOffset;
  rightOffset = centre - rightOffset;
}

void start(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}

void setup() {
  
  //Sensor de Distancia 
  Serial.begin(9600);

  calibrate();
  start();
}

void loop() { 
  
//  Velocidade dos motores = 70
  left = startSpeed;
  right = startSpeed;

  //Le os sensores e adiciona os deslocamentos
  sensor1 = analogRead(2) + leftOffset;
  sensor2 = analogRead(5);
  sensor3 = analogRead(3) + rightOffset;

  //Se o sensor1 for maior do que o sensor do centro + limiar,
  // vire para a direita
  if(sensor1 > (sensor2 + threshold)){
    Serial.println("Vira para DIREITA");
    left = startSpeed + rotate;
    right = startSpeed - rotate;
  }

  //Se o sensor3 for maior do que o sensor do centro + limiar,
  // vire para a esquerda
  if(sensor3 > (sensor2 + threshold)){
    Serial.println("Vira para ESQUERDA");
    left = startSpeed - rotate;
    right = startSpeed + rotate;
  }

  //Envia os valores de volicidade para os motores
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,left);
  analogWrite(ENB,right);
}
