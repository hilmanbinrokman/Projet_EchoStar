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



## Fonctionnalités principales
1. Lecture des données du capteur BME680 :
  - Température (°C)
  - Humidité relative (%)
  - Pression atmosphérique (hPa)
  - Résistance des gaz (KOhms)

2. Transmission des données via UART vers le module EchoStar.
3. Affichage des mesures sur le port série USB.
4. Configuration automatique du capteur BME680 :
  - Suréchantillonnage de la température, humidité et pression.
  - Activation du filtre IIR pour la stabilité des mesures.
  - Activation du chauffage de la résistance de gaz.

## Utilisation
1. Démarrer le programme en connectant le microcontrôleur à votre PC.
2. Ouvrir un moniteur série avec un baudrate de 115200.
3. Observer les valeurs mesurées en temps réel.
4. Si nécessaire, envoyer des commandes UART au module EchoStar.

## Exemple de sortie
`EchoStar BME680 Test  
Temperature = 24.5 *C  
Pressure = 1012.8 hPa  
Humidity = 50.3 %  
Gas = 150.2 KOhms`

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
