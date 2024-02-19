#!/bin/bash
# My Arduino sketch flashing script

# Set the board and port (replace with your actual board and port)
BOARD="arduino:avr:uno"
PORT="/dev/ttyACM0"

# # Compile the sketch
# arduino-cli compile --export-binaries -b $BOARD test/

# Upload the compiled sketch to the board
arduino-cli upload -p $PORT --fqbn $BOARD test/
 
echo "Arduino flashed successfully!"
