#include "Solenoid.h"
#include "SensorTask.h"

sensor_data_t gSensorData;

void setup() {

  solenoid_init(SOLENOID1);
  solenoid_init(SOLENOID2);

  delay(2000);
  
  sensor_init();

}

void loop() {

  //solenoid_open(SOLENOID1);
  //solenoid_open(SOLENOID2);

  sensor_task(&gSensorData);

  sensor_print(&gSensorData);

  //delay(1000);

  //solenoid_close(SOLENOID1);
  //solenoid_close(SOLENOID2);

  //delay(1000);

}
