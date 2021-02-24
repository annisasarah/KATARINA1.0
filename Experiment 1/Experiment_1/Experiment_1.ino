#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHT_PIN D5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  dht.begin();
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  // put your main code here, to run repeatedly:
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  display.clearDisplay();

  if (isnan(humid) || isnan(temp)) {   
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Failed to read from DHT sensor!");
    Serial.print("Failed to read from DHT sensor!");
    display.display();
    return;
  }

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(temp);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(humid);
  display.print(" %");
  
  display.display();

  Serial.print("Humidity = ");
  Serial.println(humid);
  Serial.print("Temperature = ");
  Serial.println(temp);

  delay(5000);
}
