#include<Wire.h> 

void setup()
{
  Serial.begin(9600);                        //Begins Serial Communication at 9600 baud rate
  Wire.begin();                              // Começa a comunicação I2C no pino (A4, A5)
}

void loop()
{
  Wire.requestFrom(8,1); // solicitar 1 byte do arduino escravo (8)
  int MasterReceive = Wire.read(); // recebe um byte do arduino escravo e armazena em MasterReceive
  Serial.println(MasterReceive); 
  Wire.beginTransmission(9); // inicia a transmissão para o arduino escravo (8)
  Wire.write(MasterReceive);                          // envia um valor POT convertido de um byte para o escravo
  Wire.endTransmission();                          // pare de transmitir
}