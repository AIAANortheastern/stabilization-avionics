#include "solenoid.h"
#include <Arduino.h>

/*
 * initialization function for solenoid
 * sets pin of solenoid as an output
 */
void solenoid_init(int solenoidPin){

  pinMode(solenoidPin, OUTPUT);
  
}

/*
 * function to open solenoid
 * sets solenoidPin high
 */
void solenoid_open(int solenoidPin){

  digitalWrite(solenoidPin, HIGH);
  
}

/*
 * function to close solenoid
 * sets solenoidPin low
 */
void solenoid_close(int solenoidPin){
 
  digitalWrite(solenoidPin, LOW);
  
}



