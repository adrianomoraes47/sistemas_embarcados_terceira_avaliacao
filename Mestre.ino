#include<Wire.h> 

int SlaveReceived = 0;

void setup()
{
  Serial.begin(9600);                    //Começa a comunicação serial na taxa de transmissão de 9600
  Wire.begin(9);                          //Começa a comunicação I2C com Slave Address como 8 no pino (A4, A5)
  Wire.onReceive(receiveEvent);           //Chamada de função quando o Slave recebe valor do mestre
}

void loop()
{
 Serial.println(SlaveReceived);
 analogWrite(9, SlaveReceived); 
}

void receiveEvent (int howMany)                    // Esta função é chamada quando o Slave recebe valor do mestre
{
   SlaveReceived = Wire.read();                    // Usado para ler o valor recebido do mestre e armazenar na variável SlaveReceived
}