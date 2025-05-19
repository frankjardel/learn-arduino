// Node MCU
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid="NodeMCU";
const char* password="snoopdogg";

ESP8266WebServer server(80);

const int pin7 = 7;
const int pin6 = 6;

String command;

// Servo
#include <Servo.h>
Servo myservo;
int position;

void setup() {
  Serial.begin(115200);

  // Connecting WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  // Serial.print("AP IP address: ");
  // Serial.println(myIP);
 
  // Starting WEB-server 
  server.on ( "/", HTTP_handleRoot );
  server.onNotFound ( HTTP_handleRoot );
  server.begin();

  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);

  // Servo
  //myservo.attach(16);

  // pinMode(LED_BUILTIN, OUTPUT);

  // digitalWrite(LED_BUILTIN, LOW);
  // delay(500);
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(500);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(500);
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(500);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(500);
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(500);

  delay(5000);

  digitalWrite(pin7, HIGH);
  digitalWrite(pin6, LOW);
  delay(2000);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, LOW);
  delay(2000);
}

void loop() {
  server.handleClient();

  //command = server.arg("State");
  command = Serial.read();
  
  // front
  if (String(command) == "f") {
    Serial.println(command);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, HIGH);
  }
  //Back
  else if (String(command) == "s") {
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, LOW);
  }
  else if (String(command) == "b") {
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
  }
  // Left
  if (command == "L") {
    for (position = 180; position >= 0; position -= 2) {
      myservo.write(position);
      delay(5);
    };
  }
  // right
  else if (command == "R") {
    for (position = 0; position <= 180; position += 2) {
      myservo.write(position);
      delay(5);
    };
  }
}

void HTTP_handleRoot(void) {

  if( server.hasArg("State") ){
    //Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
