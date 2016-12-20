
int ENA=5;//connected to Arduino's port 5(output pwm)
int IN1=2;//connected to Arduino's port 2
int IN2=3;//connected to Arduino's port 3
int ENB=6;//connected to Arduino's port 6(output pwm)
int IN3=4;//connected to Arduino's port 4
int IN4=7;//connected to Arduino's port 7

void setup() {
  // put your setup code here, to run once:
 pinMode(ENA,OUTPUT);//output
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,LOW);
 digitalWrite(ENB,LOW);//stop driving
  
 digitalWrite(IN1,HIGH); //setting motorB's directon
 digitalWrite(IN3,HIGH);
 
 digitalWrite(IN2,LOW);//setting motorA's directon
 digitalWrite(IN4,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  analogWrite(ENA,255);//start driving motorA
  analogWrite(ENB,255);//start driving motorB
}
