/*
 * WiFi Web Server for the On-Board ESP32-S3 NeoPixel
 *
 * Connects to WiFi and starts a web server.
 * http://[your-ip]/H turns the LED White
 * http://[your-ip]/L turns the LED Off
*/

#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

const char* ssid = "BELL614-2.4";     // your network SSID (name)
const char* pass = "120120120";       // your network password

WiFiServer server(80);

// 2.create global neopixel led object 
const int ledPin = 38;
Adafruit_NeoPixel LED_RGB(1, ledPin, NEO_GRBW + NEO_KHZ800);
void printWifiStatus();
void setup() {
  Serial.begin(115200); // baud rate

  // init LED
  LED_RGB.begin();
  LED_RGB.setBrightness(150);
  LED_RGB.setPixelColor(0, 0); // make led off at default state
  LED_RGB.show();

  // connect to wifi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // Start the server
  server.begin();
  Serial.println("Server started");

  printWifiStatus();
}


void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {
    Serial.println("New client");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == '\n') {

          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println(); 

            // Send the HTML content
            client.print("Click <a href=\"/H\">here</a> to turn the LED ON (White)<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED OFF<br>");

            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        // control led based off button press
        if (currentLine.endsWith("GET /H")) {
          // set to white
          LED_RGB.setPixelColor(0, LED_RGB.Color(255, 255, 255, 0));
          LED_RGB.show();
        }
        if (currentLine.endsWith("GET /L")) {
          // turn off
          LED_RGB.setPixelColor(0, 0);
          LED_RGB.show(); // This sends the data!
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client disconnected");
  }
}

void printWifiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}