//Progama : Envio SMS com o GSM Shield
//Alteracoes e adaptacoes : FILIPEFLOP
 
#include "SIM900.h"
#include <SoftwareSerial.h>
//Carrega a biblioteca SMS
#include "sms.h"
 
SMSGSM sms;
 
int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];
 
void setup()
{
     //Inicializa a serial 
     Serial.begin(9600);
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
        int i = 10;
        String a = String("Arduino SMS " + String(i));
        char charBuf[50];
        a.toCharArray(charBuf, 50);
      
       //Envia um SMS para o numero selecionado
       //Formato sms.SendSMS(<numero>,<mensagem>)
       if (sms.SendSMS("+5527981493334", charBuf)){
          Serial.println("nSMS sent OK"); 
       }else{
          Serial.println("nSMS sent ERROR"); 
       }
       
     }
}
 
void loop()
{
     if(started) 
     {
       //Aguarda SMS e mostra o texto no serial monitor
       //Metodo depreciado
//       if(gsm.readSMS(smsbuffer, 160, n, 20)) 
//       {
//          Serial.println(n);
//          Serial.println(smsbuffer);
//          delay(5000);
//       }
       sms.GetSMS(1,n,20,smsbuffer,160);
       Serial.println(n);
       Serial.println(smsbuffer);
       delay(1000);
     }
}
