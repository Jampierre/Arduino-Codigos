#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
SMSGSM sms;


int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

char sms_position;
char phone_number[20];
char sms_text[100];
int i;

void setup()
{
    Serial.begin(115200);
    
    if (gsm.begin(9600)) 
    {
        Serial.println("\nstatus=READY");
        started=true;
    } 
    else 
        Serial.println("\nstatus=IDLE");

//    if(started) 
//    {
//        if (sms.SendSMS("+5527981493334", "Arduino SMS"))
//        {
//          Serial.println("\nSMS sent OK.");
//        }
//        else
//        {
//          Serial.println("\nError sending SMS.");
//        }      
//    }
};

void loop()
{
  Serial.print("Introduza um número de telemóvel: ");
  char remoteNum[20];  // telephone number to send sms
  readSerial(remoteNum);
  Serial.println(remoteNum);

  // sms text
  Serial.print("Agora, insira o conteúdo do SMS: ");
  char txtMsg[200];
  readSerial(txtMsg);
  Serial.println("ENVIANDO");
  Serial.println();
  Serial.println("Mensagem:");
  Serial.println(txtMsg);

  if(started) 
    {
        if (sms.SendSMS(remoteNum, txtMsg))
        {
          Serial.println("\nSMS enviado OK.");
        }
        else
        {
          Serial.println("\nErro ao enviar SMS.");
        }      
    }
  
    if(started) 
    {
        sms_position=sms.IsSMSPresent(SMS_UNREAD);
        if (sms_position) 
        {
            Serial.print("SMS postion:");
            Serial.println(sms_position,DEC);
//            sms.GetSMS(sms_position, phone_number, sms_text, 100);
            Serial.println(phone_number);
            Serial.println(sms_text);
        }      
        delay(2000);
    }
};

/*
  Read input serial
 */
int readSerial(char result[]) {
  int i = 0;
  while (1) {
    while (Serial.available() > 0) {
      char inChar = Serial.read();
      if (inChar == '\n') {
        result[i] = '\0';
        Serial.flush();
        return 0;
      }
      if (inChar != '\r') {
        result[i] = inChar;
        i++;
      }
    }
  }
}
