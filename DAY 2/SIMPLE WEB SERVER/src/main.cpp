#include <Arduino.h>
#include <ESP8266WiFi.h>
// put function declarations here:

const char *ssid = "your-ssid";         // Replace with your WiFi SSID
const char *password = "your-password"; // Replace with your WiFi password

String html = "<html>\
<head><title>Simple Web Server</title></head>\
<body>\
<h1>Welcome to the Simple Web Server</h1>\
<p>This is a basic web server running on ESP8266.</p>\
</body>\
</html>";

WiFiClient client; // Create a WiFi client object
void setup()
{
  Serial.begin(115200); // Initialize serial communication at 115200 baud rate
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi..."); // Connect to WiFi
  while (WiFi.status() != WL_CONNECTED)    // Wait for connection
  {
    Serial.print(".");
    delay(1000); // Wait for a second
  }
  // put your setup code here, to run once:
}

void loop()
{
  if (client.connect("your-server-ip", 80)) // Replace with your server's IP address
  {
    Serial.println("Connected to server");
    client.print("POST / HTTP/1.1\r\n");
    client.print("Host: your-server-ip\r\n");
    client.print("Content-Type: text/html\r\n");
    client.print("Content-Length: ");
    client.print(html.length());
    client.print("\r\n\r\n");
    client.print(html); // Send the HTML string as the body
    Serial.println("Request sent");
  }
  else
  {
    Serial.println("Connection failed");
  }
}