#include <AFMotor.h>
char entrada;
AF_DCMotor motor_tra(1);
AF_DCMotor motor_dir(2);

void setup() {
  Serial.begin(9600);
  motor_tra.setSpeed(180);
  motor_dir.setSpeed(180);
  motor_tra.run(RELEASE);
  motor_dir.run(RELEASE);
}
void loop() {
  while (Serial.available() >0){
    entrada = Serial.read();
  
    if (entrada == 0x38){
      motor_tra.run(RELEASE);
      motor_tra.run(BACKWARD);
    }
    else if (entrada == 0x32){
      motor_tra.run(RELEASE);
      motor_tra.run(FORWARD);
    }
    else if (entrada == 0x34){
      motor_dir.run(RELEASE);
      motor_dir.run(FORWARD);
    }
    else if (entrada == 0x36){
      motor_dir.run(RELEASE);
      motor_dir.run(BACKWARD);
    }
    else if (entrada == 0x44){
      motor_tra.run(RELEASE);
      motor_dir.run(RELEASE);
    }
  }
}
