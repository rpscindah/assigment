#include <WiFi.h>
#include <HTTPClient.h>

int pin = 25;

const char* ssid = "IP 50 PROMAGH";
const char* pass = "hepiyepiye";

const String url = "http://192.168.123.40:5000/sensor/gas";

void setup() {
  Serial.begin(9600);
  Serial.println("Connecting to wifi...");

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(200);
  }
  Serial.println("Connected to wifi.");
}

void loop() {
  delay(1000);
  int g = analogRead(pin);

  if (WiFi.status() != WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;

    http.begin(client, url);
    int res = http.POST(String(g));

    Serial.println(res);

    http.end();
  }else{
    Serial.println("Disconnected.");
  }
}
