/**
 * @file adafruit_motor_driver.h
 * @brief Motor device driver for the Adafruit motor shield.
 * @author Miguel Grinberg
 */

#include "motor_driver.h"

int ENA=5;//connected to Arduino's port 5(output pwm)
int IN1=2;//connected to Arduino's port 2
int IN2=3;//connected to Arduino's port 3
int ENB=6;//connected to Arduino's port 6(output pwm)
int IN3=4;//connected to Arduino's port 4
int IN4=7;//connected to Arduino's port 7

namespace Michelino
{
    class Motor : public MotorDriver
    {
    public:
        /*
         * @brief Class constructor.
         * @param number the DC motor number to control, from 1 to 4.
         */
        Motor(int number)
            : /*MotorDriver(),*/ /*motor(number),*/ currentSpeed(0)
        {
        }

        void setSpeed(int speed)
        {
            currentSpeed = speed;
            if (speed >= 0) {
                digitalWrite(IN1,HIGH); //setting motorB's directon
                digitalWrite(IN3,HIGH);
 
                digitalWrite(IN2,LOW);//setting motorA's directon
                digitalWrite(IN4,LOW);
            
                analogWrite(ENA,speed);//start driving motorA
                analogWrite(ENB,speed);//start driving motorB
                //motor.setSpeed(speed);
                //motor.run(FORWARD);
            }
            else {
                digitalWrite(IN1,LOW); //setting motorB's directon
                digitalWrite(IN3,LOW);
 
                digitalWrite(IN2,HIGH);//setting motorA's directon
                digitalWrite(IN4,HIGH);
            
                analogWrite(ENA,-speed);//start driving motorA
                analogWrite(ENB,-speed);//start driving motorB
                //motor.setSpeed(-speed);
                //motor.run(BACKWARD);
            }
        }
        
        int getSpeed() const
        {
            return currentSpeed;
        }
        
    private:
//        AF_DCMotor motor;
        int currentSpeed;
    };
};
