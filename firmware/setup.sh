#!/bin/bash

set -e 

#Install Arduino CLI
sudo snap install arduino-cli 
sudo snap connect arduino-cli:raw-usb 

#Verify the installation by running
arduino-cli version

#Create a configuration file
arduino-cli config init

# Set up additional board URLs (esp32)
arduino-cli config add board_manager.additional_urls https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

# Set up additional board URLs (esp8266)
arduino-cli core update-index --additional-urls https://arduino.esp8266.com/stable/package_esp8266com_index.json

# update the index
arduino-cli core update-index

#install the core for your board
arduino-cli core install arduino:avr

#verify we have installed the core properly by running
arduino-cli core list

echo "Arduino setup completed!"


