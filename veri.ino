#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include <dht11.h>

const byte address[6] = "00001";

RF24 radio(9, 8);

int data[3];
int trigPin = 4;
int echoPin = 3;
int sure;
int uzaklik;
int dht11Pin = 2;
float sicaklik, nem;
dht11 DHT11;

void setup()
{
  
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH, 11600);
  data[0] = (sure*0.0345/2);
  DHT11.read(dht11Pin);
  sicaklik = (float)DHT11.temperature;
  nem = (float)DHT11.humidity;
  data[1] = sicaklik;
  data[2] = nem;
  Serial.println(data[0]);
  Serial.println(data[1]);
  Serial.println(data[2]);
  radio.write(data, sizeof(data));
  delay(5000);
}
