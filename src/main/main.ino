#include "solenoid.h"

void setup() {

  solenoid_init(SOLENOID1);
  solenoid_init(SOLENOID2);

}

void loop() {

  solenoid_open(SOLENOID1);
  solenoid_open(SOLENOID2);

  delay(1000);

  solenoid_close(SOLENOID1);
  solenoid_close(SOLENOID2);

  delay(1000);

}
