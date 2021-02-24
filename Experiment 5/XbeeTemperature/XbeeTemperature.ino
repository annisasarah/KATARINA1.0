#include <DHT.h>



#define DHT11_PIN 5
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);
unsigned long interval = 5000; // interval pengiriman data dalam mili second
unsigned long previousMillis = 0;

void setup() {
  pinMode(A0, OUTPUT); //temp up 1
  pinMode(A1, OUTPUT); //temp down 2
  pinMode(A2, OUTPUT); //power 3
  delay(1000);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval)
  {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print ("Humidity : ");
  Serial.println (h);//software serial ke zigbee
  Serial.print ("Temperature : ");
  Serial.println (t);
  delay (1000);
  previousMillis = currentMillis;
  }
}
