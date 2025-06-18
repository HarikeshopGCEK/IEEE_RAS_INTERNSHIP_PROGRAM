#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
const char *ssid = "your-ssid";         // Replace with your WiFi SSID
const char *password = "your-password"; // Replace with your WiFi password
#define DHTPIN 2                        // Pin where the DHT sensor is connected
#define DHTTYPE DHT11                   // DHT 11
const char *apiKey = "your-api-key";    // Replace with your ThingSpeak API key
unsigned long channelID = 123456;       // Replace with your ThingSpeak channel ID
WiFiClient client;                      // Create a WiFi client object
DHT dht(DHTPIN, DHTTYPE);               // Create a DHT object
// put function declarations here
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
  dht.begin(); // Initialize the DHT sensor
}

void loop()
{
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(channelID, apiKey);
  delay(15000); // Wait 15 seconds between updates
}
