#include <Arduino.h>
#define MOTOR_PIN_1 3 // Define pin for motor control 1
#define MOTOR_PIN_2 4 // Define pin for motor control 2
#define MOTOR_PIN_3 5 // Define pin for motor control 3
#define MOTOR_PIN_4 6 // Define pin for motor control 4

#define ENA 10 // Define pin for enabling the motor driver
#define ENB 11 // Define pin for PWM control

#define LSPEED 255 // Define speed for the motor (0-255)
#define RSPEED 255 // Define speed for the motor (0-255)

void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopMotors();
// Function to move the motors forward

void setup()
{
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PIN_3, OUTPUT);
  pinMode(MOTOR_PIN_4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  moveForward();  // Move forward
  delay(2000);    // Move for 2 seconds
  stopMotors();   // Stop motors
  delay(1000);    // Wait for 1 second
  moveBackward(); // Move backward
  delay(2000);    // Move for 2 seconds
  stopMotors();   // Stop motors
  delay(1000);    // Wait for 1 second
  turnLeft();     // Turn left
  delay(2000);    // Turn for 2 seconds
  stopMotors();   // Stop motors
  delay(1000);    // Wait for 1 second
  turnRight();    // Turn right
  delay(2000);    // Turn for 2 seconds
}

void moveForward()
{
  digitalWrite(MOTOR_PIN_1, HIGH);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, HIGH);
  digitalWrite(MOTOR_PIN_4, LOW);
  analogWrite(ENA, LSPEED); // Set speed for left motors
  analogWrite(ENB, RSPEED); // Set speed for right motors
  Serial.println("Moving Forward");
}
void moveBackward()
{
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, HIGH);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, HIGH);
  analogWrite(ENA, LSPEED); // Set speed for left motors
  analogWrite(ENB, RSPEED); // Set speed for right motors
  Serial.println("Moving Backward");
}
void turnLeft()
{
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, HIGH);
  digitalWrite(MOTOR_PIN_3, HIGH);
  digitalWrite(MOTOR_PIN_4, LOW);
  analogWrite(ENA, LSPEED); // Set speed for left motors
  analogWrite(ENB, RSPEED); // Set speed for right motors
  Serial.println("Turning Left");
}
void turnRight()
{
  digitalWrite(MOTOR_PIN_1, HIGH);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, HIGH);
  analogWrite(ENA, LSPEED); // Set speed for left motors
  analogWrite(ENB, RSPEED); // Set speed for right motors
  Serial.println("Turning Right");
}
void stopMotors()
{
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
  analogWrite(ENA, 0); // Stop left motors
  analogWrite(ENB, 0); // Stop right motors
  Serial.println("Motors Stopped");
}