#include <Arduino.h>
#include <DHT.h>

#define DHTPIN D6
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);                  // Initialize serial communication at 9600 baud rate
  Serial.println("DHT11 Sensor Test"); // Print a message to the serial monitor
  dht.begin();                         // Initialize the DHT sensor
  pinMode(DHTPIN, INPUT);              // Set the DHT pin as an input
}

void loop()
{
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the values to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("°C");
}

// put function definitions here: