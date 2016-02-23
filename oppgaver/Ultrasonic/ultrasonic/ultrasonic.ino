/*
 Name:    DistanceBeeper.ino
 Created: 2/15/2016 9:56:04 PM
 Author:  ArildJohan
*/

#include "Ultrasonic.h"

const int buzzerPin = 
const int redLedPin = 
const int greenLedPin = 
Ultrasonic ultrasonic(<pin>,<pin>); //(Trig,Echo)

void setup() {
  Serial.begin(9600);
}

void loop() {
  //hent verdi fra sensor

  //skriv verdi til lamper og buzzer
}
