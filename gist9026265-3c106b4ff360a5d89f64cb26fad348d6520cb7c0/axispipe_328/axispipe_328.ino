#include <Servo.h>

Servo ch[6];

unsigned char buff[3];
unsigned short count;
unsigned short kcount = 0;
void TurnOn()  {
    ch[0].attach(3);    
    ch[1].attach(5);    
    ch[2].attach(6);    
    ch[3].attach(9);    
    ch[4].attach(8);       
    ch[5].attach(10); 
    digitalWrite(13, HIGH);
    Serial.println("Controller ON");
}

void TurnOff()  {
    for(int i=0;i<6;i++)    
        ch[i].detach();
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW); 
    digitalWrite(13, LOW);              
    Serial.println("Controller OFF");
}

void KeepAlive()  {
   TCCR2B = 0x00;
   TCNT2 = 0x00;
   TIFR2  = 0x00;
   TIMSK2 = 0x01;
   TCCR2A = 0x00;
   TCCR2B |= (1<< CS12) | (1<< CS10);
   kcount = 0;
}

ISR(TIMER2_OVF_vect)  {
  //We didnt receive the signal yet. So we must shutdown the output
  kcount++;
  if(kcount == 255)
    TurnOff();
   TCCR2B = 0x00;
   TCNT2 = 0x00;
   TIFR2  = 0x00;
   TIMSK2 = 0x01;
   TCCR2A = 0x00;
   TCCR2B |= (1<< CS12) | (1<< CS10); 
}

void setup()  {
   Serial.begin(38400); 
   Serial.println("Inititializing controllers");
   pinMode(13, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   
   digitalWrite(3, LOW);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   
   count = 0;
   Serial.println("AxisPipe Started!");
   KeepAlive();
}

void loop()  {
  short val;
  if(count == 3)  {
       count = 0;
       val = buff[1] + buff[2] * 256;
       switch(buff[0])  {
          case 0:
          case 1:
          case 2:
          case 3:
            ch[buff[0]].writeMicroseconds(val);
            break;
          case 4:  break; //  Nothing on 328
          case 5: TurnOn();  break;
          case 6: TurnOff(); break;
          case 7:
          case 8: // Aux Outputs
            ch[buff[0]-3].writeMicroseconds(val);
            break;           
          case 9: break;
          default:
            Serial.println("Unknown CMD");
       }
       KeepAlive();
  }
  if (Serial.available() > 0) {
     buff[count] = Serial.read();
     count++; 
   } 
  
}