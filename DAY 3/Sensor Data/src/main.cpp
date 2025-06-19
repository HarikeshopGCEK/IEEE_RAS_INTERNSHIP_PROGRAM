#include <Arduino.h>
#define SENSOR_PIN A0 // Define the analog pin for the sensor
#define MAX_VALUE 210
#define MIN_VALUE 560

int sensorValue;
int soilMoisture;

void setup()
{
    Serial.begin(9600);         // Initialize serial communication at 9600 baud rate
    pinMode(SENSOR_PIN, INPUT); // Set the sensor pin as input
}

void loop()
{
    sensorValue = analogRead(SENSOR_PIN);                          // Read the sensor value
    soilMoisture = map(sensorValue, MIN_VALUE, MAX_VALUE, 0, 100); // Map the sensor value to percentage
    Serial.print("Soil Moisture: ");
    Serial.print(soilMoisture);
    Serial.println("%");
    delay(1000); // Wait for 1 second before the next reading
}