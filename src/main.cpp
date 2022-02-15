/*
  Titre      : Communication_2uC
  Auteur     : Crepin Vardin Fouelefack
  Date       : 11/02/2022
  Description: Controle de l'intensite d'une led placee sur le uC1010 grace a un potentiometre sur le uC1000
  Version    : 0.0.1
*/

#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"
#include <Wire.h>                       //Pour la communication I2C

const int ANALOG_PIN           = A1;    // Broche pour le potentionmetre

//Declaration des variables
int TentionBrocheAnalogique = 0;         // Pour contenir la tension sur la broche Analogique
int Intensite               = 0;         // Va de (0-255) Pour contenir la valeur de la broche Analog convertie
int micro2 =0;

void setup() {
//Serial.begin(9600);
// initialize serial communications at 9600 bps:
//Serial.begin(9600);
 
//wifiConnect();                  //Branchement au réseau WIFI
//MQTTConnect();                  //Branchement au broker MQTT

  // Démarrer le bus I2C en tant que maître
  Wire.begin();

  pinMode(ANALOG_PIN, INPUT);  //Broche analogue en mode lecture pour lire la tention au niveau du potentionmetre (0-1023)
 
}

// Boucle infinie qui permet au uC de faire une ou plusieurs taches sans arrêt
void loop() {
  
TentionBrocheAnalogique = analogRead(ANALOG_PIN);         //De (0-1023)
  Intensite             = map(TentionBrocheAnalogique,0,1023,0,255);  //De (0-255)

 // micro2 = Intensite / 4;   Pour un autre uC

  Wire.beginTransmission(9); // transmettre à l'appareil #9
  Wire.write(Intensite); // envoie x
  Wire.endTransmission(); // arrête de transmettre

// Pour un autre uC
 /*  Wire.beginTransmission(8); // transmettre à l'appareil #8
     Wire.write(micro2); // envoie x
     Wire.endTransmission(); // arrête de transmettre    */


  /* appendPayload("ValeurBroche", NomVariable);  //Ajout de la valeur de la broche A1 au message MQTT
     appendPayload("LedRouge", LedRouge);  //Ajout de la valeur de la broche A3 au message MQTT

  sendPayload();                                   //Envoie du message via le protocole MQTT 
  */

}
