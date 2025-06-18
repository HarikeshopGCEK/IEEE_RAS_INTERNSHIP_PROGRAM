#include <Arduino.h>

void setup()
{
    Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop()
{
    // Check if data is available to read from the serial port
    if (Serial.available() > 0)
    {
        String input = Serial.readStringUntil('\n'); // Read the input until a newline character
        Serial.print("Received: ");
        Serial.println(input); // Echo the received input back to the serial monitor
        // You can add more processing logic here if needed
        if (input == "ON")
        {
            digitalWrite(LED_BUILTIN, HIGH); // Turn on the built-in LED
        }
        else if (input == "OFF")
        {
            digitalWrite(LED_BUILTIN, LOW); // Turn off the built-in LED
        }
        else
        {
            Serial.println("Unknown command. Use 'ON' or 'OFF'.");
        }
    }

    delay(100); // Add a small delay to avoid overwhelming the serial monitor
}