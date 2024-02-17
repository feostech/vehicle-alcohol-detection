#!/bin/bash

set -e 

ESP32_URL="https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"
ESP8266_URL="https://arduino.esp8266.com/stable/package_esp8266com_index.json"

#Install Arduino CLI
cd /usr/bin/
sudo apt-get install curl

#Add arduino-cli to the system path
cd /home/usr/arduino-cli/

#Verify the installation by running
arduino-cli version

#Create a configuration file
arduino-cli config init

# update the index
arduino-cli core update-index --additional-urls=$ESP32_URL
arduino-cli core update-index --additional-urls=$ESP8266_URL

#install the core for your board
arduino-cli core install esp32:esp32
arduino-cli core install esp8266:esp8266

#verify we have installed the core properly by running
arduino-cli core list

echo "Arduino setup completed!"


