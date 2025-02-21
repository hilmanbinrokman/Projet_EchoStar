# Projet EchoStar
### Auteurs
*Hilman Bin Rokman*  
*Anissa Boumahdi*

## Description

Ce projet permet de faire l'interface entre un module EchoStar et un capteur BME680 via un microcontrôleur. Il réalise la transmission des données du capteur vers le module EchoStar et affiche les valeurs mesurées sur un port série USB. Le code prend en charge la gestion de l'alimentation et la configuration du capteur pour mesurer la température, l'humidité, la pression atmosphérique et la résistance des gaz.

## Matériel requis

- Microcontrôleur compatible avec la bibliothèque Adafruit BME680  
- Capteur BME680 (via I2C)  
- Module EchoStar  
- Câblage pour connexion I2C et UART  

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

`setup()`  
Initializes pins, serial communication, and the BME680 sensor.  
Configures oversampling and filtering for accurate readings.  

`loop()`  
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
