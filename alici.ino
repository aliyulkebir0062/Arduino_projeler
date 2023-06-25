#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

const byte address[6] = "00001";

RF24 radio(9, 8);

int data[1];
int sure = 0;
int uzaklik = 0;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

}

void loop()
{
  if ( radio.available() ) //radyo ile temas kurulduysa
  {
    radio.read(data, sizeof(data));
    uzaklik = data[0];
    Serial.println(uzaklik);
    delay(1000);
  }
}
