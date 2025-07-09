//Receiver code
const char* ssid = "********************************";

const char* password = "********************************";

String apiKey = "********************************";
#include <WiFi.h>

#include <SPI.h>

#include <nRF24L01.h>

#include <RF24.h>

 

String apiKey = "FTY1Txxxxxxx1NGU";

 

const char* ssid = "********************************";

const char* password = "********************************";

 

const char* server = "api.thingspeak.com";

 

RF24 radio(4, 5); 

const uint64_t address = 0xF0F0F0F0E1LL;

 

struct MyVariable

{

  byte soilmoisturepercent;

  byte nitrogen;

  byte phosphorous;

  byte potassium;

  byte temperature;

};

MyVariable variable;

 

WiFiClient client;

 

void setup() 

{

  Serial.begin(115200);

  radio.begin();                  //Starting the Wireless communication

  radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data

  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.

  radio.startListening();              //This sets the module as receiver

  

  Serial.println("Receiver Started....");

  Serial.print("Connecting to ");

  Serial.println(ssid);

  Serial.println();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 

  {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

}

 

int recvData()

{

  if ( radio.available() ) 

  {

    radio.
