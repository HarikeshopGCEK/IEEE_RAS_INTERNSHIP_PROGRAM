#include <Arduino.h>

#define LED_PIN D4
// int ledPin = D4; // This is the pin number for the LED, defined in pins_arduino.h
// You can also use 2 directly as pin number, but using D4 makes the code more readable.

void setup()
{
  Serial.begin(9600);              // Initialize serial communication at 9600 baud rate
  Serial.println("Hello, World!"); // Print a message to the serial monitor
  pinMode(LED_PIN, OUTPUT);        // Set the LED pin as an output
  digitalWrite(LED_PIN, HIGH);     // Turn the LED off
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, LOW);  // Turn the LED on
  delay(1000);                 // Wait for a second
  digitalWrite(LED_PIN, HIGH); // Turn the LED off
  delay(1000);                 // Wait for a second\
  
}
