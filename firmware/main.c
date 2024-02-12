#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define ANALOG_PIN A0 // Define analog pin for Alcohol Sensor
#define LED_PIN 16   //  Define GPIO pin for LED indication

const char* ssid = "SSID";
const char* password = "SSID-Password";
const char* mqtt_server = "IP-Address";  // MQTT Broker IP Address
const uint16_t mqtt_server_port = 1884;   // MQTT Broker Port 
const char* mqttTopic = "Topic-name";      // MQTT topic for Alcohol Sensor

WiFiClient wifiClient;  // Create an instance of WiFiClient for managing WiFi connection 
PubSubClient mqttClient(wifiClient); // Create an instance of MQTTClient for communication using WiFiClient

// Function to Set up WiFi Connection
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("WiFi connected");
}

// Function to connect the MQTT broker
void connect() {
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    String mqttClientId = "";
    if (mqttClient.connect(mqttClientId.c_str(), mqtt_server, ssid)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" will try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  setup_wifi();
  mqttClient.setServer(mqtt_server, mqtt_server_port);
}

void loop() {
  if (!mqttClient.connected()) {
    connect();
  }
  int sensorValue = analogRead(ANALOG_PIN);  // Read analog value from alcohol sensor
  if (sensorValue > 400) {  // Check if alcohol level is above a threshold or not 
    digitalWrite(LED_PIN, LOW); // Turn ON the LED 
    Serial.print("Value = ");
    Serial.print(sensorValue);
    Serial.println(" ALERT: Alcohol detected!");
    mqttClient.publish(mqttTopic, ("ALERT: Alcohol detected!")); // Publish alert message to MQTT 
  } else {
    digitalWrite(LED_PIN, HIGH); // Turn OFF the LED
  }
  mqttClient.loop();
  delay(1000);
}
