#include <Arduino.h>
#define IR_PIN 3
#define LED_PIN 13     // Define the pin for the LED (optional, if you want to visualize the state)
bool ledState = false; // Variable to hold the state of the LED
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);     // Initialize serial communication at 9600 baud rate
  pinMode(IR_PIN, INPUT); // Set the IR sensor pin as input
  Serial.println("IR Sensor as Switch Example");
}

void loop()
{
  // put your main code here, to run repeatedly:
  int sensorValue = digitalRead(IR_PIN);
  if (sensorValue == HIGH && !ledState)
  {
    ledState = true;
    Serial.println("LED is ON");
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  }
  else if (sensorValue == LOW && ledState)
  {
    ledState = false;
    Serial.println("LED is OFF");
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  }
}
