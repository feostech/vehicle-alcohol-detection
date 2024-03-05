# Arduino CLI Setup Script

This script automates the setup process for the Arduino CLI tool and installs the ESP8266 core for Arduino development.

## Prerequisites

Before running this script, ensure you have the following:

- **Linux environment**: This script is designed to work on Linux systems.
- **bash shell**: Ensure you are using the bash shell.
- **Internet connection**: The script requires an internet connection to download dependencies and install the Arduino CLI tool.

## Usage

### Download the Script
Clone this repository or download the `./setup.sh` script file.

### Set Execution Permissions
If needed, set execution permissions for the script:
```
chmod +x setup.sh
```

### Run the Script
Execute the script in your terminal:
```
./setup.sh
```

Follow the prompts as the script installs dependencies and sets up the Arduino CLI tool.

### Verify Installation
Once the script completes, verify that the Arduino CLI tool and ESP8266 core are installed properly:
```
arduino-cli version
arduino-cli core list
```


## Script Details

- **ESP8266_URL**: The URL for the ESP8266 board package index.
- **ARDUINO_CLI**: Path to the Arduino CLI executable (assumed to be installed in `$HOME/bin`).
- **arduino_cli_setup**: Function to set up the Arduino CLI tool.
- **Core Installation**: The script updates the core indices, installs the ESP8266 core, and lists the installed cores.
- **Error Handling**: Checks if the Arduino CLI tool is installed and installs it if not.


---

# Arduino Flashing Script

This repository contains a bash script for flashing Arduino boards using the Arduino CLI.

## Description

The script automates the process of flashing an Arduino board with a specified sketch. It detects the connected board, installs necessary libraries, compiles the sketch, and uploads it to the board.

## Prerequisites

- Arduino CLI installed and accessible from `$HOME/bin/arduino-cli`
- The board connected to the computer via USB

## Usage

1. Clone this repository to your local machine.
2. Navigate to the cloned directory.
3. Run the script with the following command:
```
./flash.sh
```

The script will execute the following steps:
- Detect the connected Arduino board.
- If the board is not detected, it will default to `esp8266:esp8266:nodemcuv2`.
- Install the `pubsubclient` library.
- Compile the sketch located in the current directory.
- Upload the compiled binaries to the board.
- Display a success message upon completion.

## Note

>This script assumes a basic Linux environment and may require adjustments for specific distributions or configurations.

## Contributing

Contributions to this project are welcome. Please fork the repository and submit a pull request with your changes.

## Acknowledgments

Thanks to the Arduino and ESP8266 communities for providing the tools and resources to make this script possible.
