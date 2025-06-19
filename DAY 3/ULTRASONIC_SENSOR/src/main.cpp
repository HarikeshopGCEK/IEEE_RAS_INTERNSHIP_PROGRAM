#include <Arduino.h>

#define TRIG 9
#define ECHO 10

float measureDistance();
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);    // Initialize serial communication at 9600 baud rate
  pinMode(TRIG, OUTPUT); // Set the trigger pin as output
  pinMode(ECHO, INPUT);  // Set the echo pin as input
  Serial.println("Ultrasonic Sensor Distance Measurement Example");
}

void loop()
{
  // put your main code here, to run repeatedly:
  float distance = measureDistance(TRIG, ECHO); // Measure distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm"); // Print the distance in centimeters
  delay(1000);           // Wait for 1 second before the next measurement
}

float measureDistance(int trigPin, int echoPin)
{
  // Send a 10 microsecond pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin to get the duration of the pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters (speed of sound is approximately 343 m/s)
  float distance = (duration * 0.0343) / 2; // Divide by 2 because the signal travels to the object and back

  return distance;
}