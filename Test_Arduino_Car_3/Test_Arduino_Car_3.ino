/*
    Teste usando o aplicativo BlueStrick
*/

#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define MAX_DISTANCE 200

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int ENA=5;//connected to Arduino's port 5(output pwm)
int IN1=2;//connected to Arduino's port 2
int IN2=3;//connected to Arduino's port 3
int ENB=6;//connected to Arduino's port 6(output pwm)
int IN3=4;//connected to Arduino's port 4
int IN4=7;//connected to Arduino's port 7

void setup() {
  //Ativando MotorA e MotorB
 pinMode(ENA,OUTPUT);//output
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,LOW);
 digitalWrite(ENB,LOW);//stop driving

  //Bluetooth
//  Serial.begin(9600);
//  pinMode(13, OUTPUT);
  
  //Sensor de Distancia 
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
        char ch = Serial.read();
        unsigned int cm = DistanceSensor.ping_cm();
        
        Serial.print("Distance: ");
        Serial.print(cm);
        Serial.println("cm");
          
        Serial.print("Received: ");
        Serial.println(ch);
       
        switch (ch)
        {
           case '8': //Frente
             //if(cm < 10){
//               analogWrite(ENA,0);//start driving motorA
//               analogWrite(ENB,0);//start driving motorB
//               break;
             //}
             Serial.println("Frente");
             digitalWrite(IN1,HIGH); //setting motorB's directon
             digitalWrite(IN3,HIGH);
 
             digitalWrite(IN2,LOW);//setting motorA's directon
             digitalWrite(IN4,LOW);
            
             analogWrite(ENA,255);//start driving motorA
             analogWrite(ENB,255);//start driving motorB
             break;
           
           case '2': //traz
           Serial.println("A traz");
             digitalWrite(IN1,LOW); //setting motorB's directon
             digitalWrite(IN3,LOW);
 
             digitalWrite(IN2,HIGH);//setting motorA's directon
             digitalWrite(IN4,HIGH);
            
             analogWrite(ENA,255);//start driving motorA
             analogWrite(ENB,255);//start driving motorB
             break;
           
           case '4': //Esquerda 
           Serial.println("Esquerda");
             //if(cm < 10){
//               analogWrite(ENA,0);//start driving motorA
//               analogWrite(ENB,0);//start driving motorB
//               break;
             //}
             analogWrite(ENA,0);//start driving motorA
             analogWrite(ENB,255);//start driving motorB
             break;
          
           case '6': //Direita
           Serial.println("Direita");
             //if(cm < 10){
//               analogWrite(ENA,0);//start driving motorA
//               analogWrite(ENB,0);//start driving motorB
//               break;
             //}  
             analogWrite(ENA,2551);//start driving motorA
             analogWrite(ENB,0);//start driving motorB
             break;
           
           default:
           Serial.println("Para");
             analogWrite(ENA,0);//start driving motorA
             analogWrite(ENB,0);//start driving motorB
        }
   }
}
