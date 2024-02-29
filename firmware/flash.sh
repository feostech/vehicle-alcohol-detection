#!/bin/bash
# Flashing script

ARDUINO_CLI=$HOME/bin/arduino-cli
BOARD_REGEX='[[:alnum:]]\+:[[:alnum:]]\+:[-_[:alnum:]]\+'
BOARD=$($ARDUINO_CLI board list | grep -o  $BOARD_REGEX) 
#If esp8266 board not detected automatically ,we give manual board name for esp8266
if [ "$BOARD" = "" ]; then
	BOARD=esp8266:esp8266:nodemcuv2
fi
PORT="/dev/ttyUSB0"

#Install Dependent libraries
$ARDUINO_CLI lib install pubsubclient &&
    
# Compile the sketch
$ARDUINO_CLI compile  --export-binaries -b $BOARD . &&

# Upload the compiled sketch to the board
$ARDUINO_CLI upload -p $PORT --fqbn $BOARD . &&
 
echo "Arduino flashed successfully!" 
