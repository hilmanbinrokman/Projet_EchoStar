# Projet EchoStar
### Authors
*Hilman Bin Rokman*  
*Anissa Boumahdi*

## Description

This project interfaces an EchoStar module with a BME680 environmental sensor. The system reads temperature, humidity, pressure, and gas resistance values from the BME680 sensor and transmits the data via serial communication. The project is designed to be used with an MCU that forwards serial signals between USB and the EchoStar module.

## Features

Reads environmental data from the BME680 sensor (temperature, pressure, humidity, gas resistance).  
Forwards data between USB and EchoStar module.  
Supports switching control signals via serial commands.  
Uses I2C communication for sensor data acquisition.  
Handles sensor initialization and configuration.  

## Hardware Requirements
Microcontroller with USB and serial communication support  
EchoStar module  
BME680 environmental sensor  
Required wiring and power components  

## Software Requirements
Arduino IDE (or compatible environment)  
Adafruit BME680 Library (GitHub Repo)  
Wire and SPI libraries  

## Installation and Setup
Connect the BME680 sensor to the MCU via I2C (SDA, SCL).  
Connect the EchoStar module to the appropriate UART pins.  
Install required libraries in the Arduino IDE.  
Upload the provided code to the microcontroller.  
Monitor sensor readings via USB serial output.  

## Code Overview

### setup()
Initializes pins, serial communication, and the BME680 sensor.  
Configures oversampling and filtering for accurate readings.  

### loop()
Continuously reads sensor data.  
Sends sensor data via EchoStar module.  
Prints sensor values to USB serial output.  

## Usage
Ensure the hardware connections are correct and power is supplied.  
Open the serial monitor (115200 baud) to view sensor readings.  
The system automatically forwards serial data and logs environmental readings.  

## Troubleshooting
If the BME680 sensor is not detected, check the wiring and I2C address.  
Ensure the EchoStar module is correctly powered and connected.  
Verify baud rates match between serial devices.  

## License
This project is open-source. Feel free to modify and share it under the applicable license.  
