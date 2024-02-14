#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define ANALOG_PIN A0
#define LED_PIN 16
#define LOOP_DELAY_MS 10
#define TIMEOUT_DELAY_MS 500

const char* ssid = "SSID";
const char* password = "SSID-Password";
const char* mqtt_server = "IP-address";
const uint16_t mqtt_server_port = 1883;
const char* mqttTopic = "Topic-name";
const int detectionThreshold = 400;
const char* vehicleNumber = "TN 36 D XXXX";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient); 

void setup_wifi() {
  delay(LOOP_DELAY_MS);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(TIMEOUT_DELAY_MS);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("WiFi connected");
}

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

void printAlert(const char* vehicleNumber) {
  Serial.print(" Vehicle ");
  Serial.print(vehicleNumber);
  Serial.println(" ALERT: Alcohol detected!");
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
  int sensorValue = analogRead(ANALOG_PIN);
  if (sensorValue > detectionThreshold) {
    digitalWrite(LED_PIN, LOW); // Turn ON the LED 
    Serial.print(" Value = ");
    Serial.print(sensorValue);
    printAlert(vehicleNumber);
    String alertMessage = "ALERT: Alcohol detected in Vehicle ";
    alertMessage += vehicleNumber;
    mqttClient.publish(mqttTopic, alertMessage.c_str());
  } else {
    digitalWrite(LED_PIN, HIGH); // Turn OFF the LED
  }
  mqttClient.loop();
  delay(1000);
}
