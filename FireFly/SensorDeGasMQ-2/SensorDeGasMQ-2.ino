// Programa : Alarme com sensor de gas MQ-2
// Autor : Arduino e Cia

// Definicoes dos pinos ligados ao sensor
int pin_d0 = 7;
int pin_a0 = A2;

int nivel_sensor = 250;

void setup()
{
  // Define os pinos de leitura do sensor como entrada
  pinMode(pin_d0, INPUT);
  pinMode(pin_a0, INPUT);
  // Inicializa a serial
  Serial.begin(9600);
}

void loop()
{
  // Le os dados do pino digital D0 do sensor
  int valor_digital = digitalRead(pin_d0);
  // Le os dados do pino analogico A0 do sensor
  int valor_analogico = analogRead(pin_a0);

  // Mostra os dados no serial monitor
  String d0 = String("Pino D0: " + String(valor_digital));
  Serial.println(d0);
  String a0 = String("Pino A0: " + String(valor_analogico));
  Serial.println(a0);
//  Serial.print("Pino D0 : ");
//  Serial.print(valor_digital);
//  Serial.print(" Pino A0 : ");
//  Serial.println(valor_analogico);
  // Verifica o nivel de gas/fumaca detectado
  if (valor_analogico > nivel_sensor)
  {
    // Liga o buzzer e o led vermelho, e
    // desliga o led verde
//    digitalWrite(pin_led_verm, HIGH);
//    digitalWrite(pin_led_verde, LOW);
//    digitalWrite(pin_buzzer, HIGH);
    Serial.println(" NIVEL ALTO ");

  }
  else
  {
    // Desliga o buzzer e o led vermelho, e
    // liga o led verde
//    digitalWrite(pin_led_verm, LOW);
//    digitalWrite(pin_led_verde, HIGH);
//    digitalWrite(pin_buzzer, LOW);
    Serial.println(" NIVEL BAIXO ");
  }
  delay(500);
}
