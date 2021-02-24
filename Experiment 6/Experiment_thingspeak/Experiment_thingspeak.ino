#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN D14

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

const char* ssid = "....";
const char* password = "....";

unsigned long myChannelNumber = ....;
const char* myWriteAPIKey = "....";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  delay(15000);
}
