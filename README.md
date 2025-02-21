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

## Dépendances
Avant d'utiliser ce programme, assurez-vous d'avoir installé les bibliothèques suivantes :
- Adafruit BME680 
- Adafruit Sensor
- Wire.h et SPI.h (inclus dans l'IDE Arduino)

## Configuration et Paramètres
Ce programme utilise les paramètres suivants :
- `SENSORS_BME680_ADDRESS` : Adresse I2C du capteur BME680.
- `SEALEVELPRESSURE_HPA` : Pression atmosphérique de référence (1013,25 hPa par défaut).
- `SWITCH_REVERSING_CONTROL_DEFAULT_VALUE` : Contrôle du signal de commutation RF.



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

## Dépannage
- Le capteur BME680 n'est pas détecté ?
  - Vérifiez les connexions I2C.
  - Assurez-vous que l'adresse I2C est correcte.
  -Testez avec un scanner I2C.

- Données incorrectes ou instables ?
  - Vérifiez l'alimentation du capteur.
  - Assurez-vous que le capteur est éloigné des sources de chaleur ou d'humidité excessives.

- Pas de communication avec EchoStar ?
  - Vérifiez les connexions UART.
  - Vérifiez le baudrate.

## License
Ce projet est sous licence MIT. Vous êtes libre de l'utiliser, de le modifier et de le partager sous réserve de mentionner les auteurs originaux.
