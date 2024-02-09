#include <ESP8266WiFi.h>

#define ANALOG_PIN A0
#define LED_PIN 16

const char *ssid = "ssid";
const char *password = "ssid-password";

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi... ");
  }
  Serial.println("Connected to WiFi ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int sensorValue = analogRead(ANALOG_PIN);
  if (sensorValue > 400) {
    digitalWrite(LED_PIN, LOW);
    Serial.print("Value = ");
    Serial.print(sensorValue);
    Serial.println(" ALERT: Alcohol detected!");
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
  delay(1000);
}
