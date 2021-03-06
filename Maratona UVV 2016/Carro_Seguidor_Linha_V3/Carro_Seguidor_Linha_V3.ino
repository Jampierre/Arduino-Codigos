//  Programa: Motor Shield com sensor TCRT5000
//
//  Created by Jampierre Vieira Rocha on 4/11/16.
//  Copyright © 2016 Jampierre Vieira Rocha. All rights reserved.

int ENA = 5; // Output pwm
int IN1 = 2;
int IN2 = 3;

int ENB = 6; // Output pwm
int IN3 = 4;
int IN4 = 7;

int sensor1, sensor2, sensor3;

// Deslocamentos de calibração
int leftOffset = 0, rightOffset = 0, centre = 0;

// Velocidade inicial e deslocamentos de rotação
int startSpeed = 70, rotate = 30;

// Limiar do sensor;
int threshold = 5;

// Velocidades iniciais dos motores esquerdos e direito
int left = startSpeed, right = startSpeed;

// Rotina de calibração do sensor
void calibrate(){
  // Executa 10x para obter uma media
  for(int x = 0; x < 10; x++){
    delay(100);
    sensor1 = analogRead(0);
    sensor2 = analogRead(1);
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
  // Ativando MotorA
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);

  // Ativando MotorB
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);



  //setting motorA's directon
    digitalWrite(IN1,HIGH); 
    digitalWrite(IN2,LOW);
    
    
 
    //setting motorB's directon
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  


  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  analogWrite(ENA,200);//start driving motorA
  analogWrite(ENB,200);//start driving motorB
}

void setup() {

  pinMode(ENA,OUTPUT);//output
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,HIGH);
 digitalWrite(ENB,HIGH);//stop driving

  //Bluetooth
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  //Sensor de Distancia 
  Serial.begin(9600);
  
//  start();
  //Sensor de Distancia
//  Serial.begin(9600);

  

//  calibrate();
  
//  delay(3000);
}

void loop() {
//  Velocidade dos motores = 70
//  left = startSpeed;
//  right = startSpeed;

  //Le os sensores e adiciona os deslocamentos
//  sensor1 = analogRead(0) + leftOffset;
//  sensor2 = analogRead(1);
//  sensor3 = analogRead(2) + rightOffset;

  //Se o sensor1 for maior do que o sensor do centro + limiar,
  // vire para a direita
//  if(sensor1 > (sensor2 + threshold)){
//    Serial.println("Vira para DIREITA");
//    left = startSpeed + rotate;
//    right = startSpeed - rotate;
//  }

  //Se o sensor3 for maior do que o sensor do centro + limiar,
  // vire para a esquerda
//  if(sensor3 > (sensor2 + threshold)){
//    Serial.println("Vira para ESQUERDA");
//    left = startSpeed - rotate;
//    right = startSpeed + rotate;
//  }

  //Envia os valores de volicidade para os motores
//  motor_esq.setSpeed(left);
//  motor_esq.run(FORWARD);
//  motor_dir.setSpeed(right);
//  motor_dir.run(FORWARD);
//  analogWrite(ENA,left);//start driving motorA
//  analogWrite(ENB,right);//start driving motorB

//  digitalWrite(IN1,HIGH); //setting motorB's directon
//  digitalWrite(IN3,HIGH);

  

//  Serial.print("left : ");
//  Serial.println(left);
//  Serial.print("right : ");
//  Serial.println(right);

//  delay(3000);
}
