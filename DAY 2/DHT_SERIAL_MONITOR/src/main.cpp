#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 2 // Pin where the DHT sensor is connected
DHT dht(DHTPIN, DHT11);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();    // Read humidity
  float t = dht.readTemperature(); // Read temperature as Celsius
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("°C");
}
