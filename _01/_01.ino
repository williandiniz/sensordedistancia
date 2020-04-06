#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger D1
#define pino_echo D3
#define pino_buzz D5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(115200);
  Serial.println("Lendo dados do sensor...");
  pinMode(pino_buzz,OUTPUT);
  digitalWrite(pino_buzz, LOW);
  
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec, inMesec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMesec = cmMsec/60;
 
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em Metros: ");
  Serial.print(inMesec);
  if ( inMesec <= 1.2 )
       digitalWrite(pino_buzz, HIGH);

  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);
  digitalWrite(pino_buzz, LOW);

}
