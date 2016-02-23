/*
 Name:    DistanceBeeper.ino
 Created: 2/15/2016 9:56:04 PM
 Author:  ArildJohan
*/

#include "Ultrasonic.h"

const int buzzerPin = 3; // connect buzzer + to D3, - to GND
const int redLedPin = 6; // must be PWM
const int greenLedPin = 9; // must be PWM
Ultrasonic ultrasonic(11, 10);//(Trig,Echo)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.Ranging(CM);
  
  int volume = 255 - distance*10;
  int ledStrength = 255 / distance;
  Serial.println(volume);
  if (volume < 0) volume = 0;
  analogWrite(buzzerPin, volume);
  analogWrite(redLedPin, ledStrength);
  analogWrite(greenLedPin, ledStrength);
}
