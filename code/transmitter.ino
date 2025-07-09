//Transmitter code
include <SPI.h>

#include <SoftwareSerial.h>

#include <OneWire.h>

#include <DallasTemperature.h>

#include <nRF24L01.h>

#include <RF24.h>

 

RF24 radio(9, 10); // CE, CSN on Blue Pill

const uint64_t address = 0xF0F0F0F0E1LL;

 

#define ONE_WIRE_BUS 5

 

#define RE 8

#define DE 7

 

const byte code[] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x03, 0x65, 0xCD};

byte values[11];

SoftwareSerial mod(2, 3);

 

const int AirValue = 645;   //you need to replace this value with Value_1

const int WaterValue = 254;  //you need to replace this value with Value_2

int soilMoistureValue = 0;

int soilmoisturepercent = 0;

 

float  temperature;

int nitrogen;

int phosphorous;

int potassium;

 

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 

struct MyVariable

{

  byte soilmoisturepercent;

  byte nitrogen;

  byte phosphorous;

  byte potassium;

  byte  temperature;

};

MyVariable variable;

 

 

void setup()

{

  Serial.begin(9600);

  mod.begin(9600);

  radio.begin();                  //Starting the Wireless communication

  radio.openWritingPipe(address); //Setting the address where we will send the data

  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.

  radio.stopListening();          //This sets the module as transmitter

  sensors.begin();

  pinMode(RE, OUTPUT);

  pinMode(DE, OUTPUT);

}

 
