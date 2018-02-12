#include "Solenoid.h"
#include "10dof.h"

void setup() {

  solenoid_init(SOLENOID1);
  solenoid_init(SOLENOID2);
  
  init();

}

void loop() {

  solenoid_open(SOLENOID1);
  solenoid_open(SOLENOID2);

  sensor_task();

  solenoid_close(SOLENOID1);
  solenoid_close(SOLENOID2);

  delay(1000);

}
