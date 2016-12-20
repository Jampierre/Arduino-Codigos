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
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
        char ch = Serial.read();
        Serial.print("Received: ");
        Serial.println(ch);
        
        switch (ch)
        {
           case 'w': //Frente
             digitalWrite(IN1,HIGH); //setting motorB's directon
             digitalWrite(IN3,HIGH);
 
             digitalWrite(IN2,LOW);//setting motorA's directon
             digitalWrite(IN4,LOW);
            
             analogWrite(ENA,255);//start driving motorA
             analogWrite(ENB,255);//start driving motorB
             break;
           
           case 's': //traz
             digitalWrite(IN1,LOW); //setting motorB's directon
             digitalWrite(IN3,LOW);
 
             digitalWrite(IN2,HIGH);//setting motorA's directon
             digitalWrite(IN4,HIGH);
            
             analogWrite(ENA,255);//start driving motorA
             analogWrite(ENB,255);//start driving motorB
             break;
           
           case 'a': //Esquerda 
             analogWrite(ENA,0);//start driving motorA
             analogWrite(ENB,255);//start driving motorB
             break;
          
           case 'd': //Direits  
             analogWrite(ENA,255);//start driving motorA
             analogWrite(ENB,0);//start driving motorB
             break;
           
           default:
             analogWrite(ENA,0);//start driving motorA
             analogWrite(ENB,0);//start driving motorB
        }
   }
  
}
