#!/bin/bash
# Flashing script

set -x
ARDUINO_CLI=$HOME/bin/arduino-cli
BOARD_REGEX='[[:alnum:]]\+:[[:alnum:]]\+:[-_[:alnum:]]\+'
BOARD=$($ARDUINO_CLI board list | grep -o  $BOARD_REGEX)
PORT="/dev/ttyACM0"
BOARD=$($ARDUINO_CLI board list | grep -o  $BOARD_REGEX) 

#If ESP8266 board not detected automatically, So we assign manual board name as ESP8266
if [ "$BOARD" = "" ]; then
	BOARD=ESP8266:ESP8266:ESP8266
fi
PORT="/dev/ttyUSB0"

#Install Dependent libraries
$ARDUINO_CLI lib install pubsubclient &&
