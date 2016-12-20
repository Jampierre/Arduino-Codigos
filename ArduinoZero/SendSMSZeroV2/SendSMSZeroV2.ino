//Progama : Envio SMS com o GSM Shield
//Alteracoes e adaptacoes : FILIPEFLOP
 
#include "SIM900.h"
//#include <SoftwareSerial.h>
//Carrega a biblioteca SMS
#include "sms.h"
 
SMSGSM sms;
 
int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];
 
void setup()
{
     //Inicializa a SerialUSB 
     Serial.begin(115200);
     Serial.println("Testando GSM shield...");
     //Inicia a configuracao do Shield
     if (gsm.begin(2400)) 
     {
       Serial.println("nstatus=READY");
       started=true;
     } 
     else Serial.println("nstatus=IDLE");
 
     if(started) 
     {
       //Envia um SMS para o numero selecionado
       //Formato sms.SendSMS(<numero>,<mensagem>)
       if (sms.SendSMS("912345678", "Arduino SMS"))
       Serial.println("nSMS sent OK");
     }
}
 
void loop()
{
     if(started) 
     {
       //Aguarda SMS e mostra o texto no SerialUSB monitor
       if(gsm.readSMS(smsbuffer, 160, n, 20)) 
       {
          Serial.println(n);
          Serial.println(smsbuffer);
          delay(5000);
       }
       delay(1000);
     }
}
