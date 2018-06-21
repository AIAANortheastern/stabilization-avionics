#include "Solenoid.h"
#include "SensorTask.h"
#include "KalmanFilter.h"
#include "rt_nonfinite.h"
#include "KalmanFilter_Initialize.h"

extern void KalmanFilter_init(void);
extern void KalmanFilter(double x[12], const double z[6]);

sensor_data_t gSensorData;

double rawSensorData[6];
double state[12];

void setup() {

  solenoid_init(SOLENOID1);
  solenoid_init(SOLENOID2);
  KalmanFilter_initialize();

  state[0] = 0;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;
  state[4] = 0;
  state[5] = 0;
  state[6] = 0;
  state[7] = 0;
  state[8] = 0;
  state[9] = 0;
  state[10] = 0;
  state[11] = 0;
  

  delay(2000);
  
  sensor_init();

}

void loop() {

  //solenoid_open(SOLENOID1);
  //solenoid_open(SOLENOID2);

  sensor_task(&gSensorData);

  //sensor_print(&gSensorData);

  rawSensorData[0] = gSensorData.gyro.x;
  rawSensorData[1] = gSensorData.gyro.y;
  rawSensorData[2] = gSensorData.gyro.z;
  rawSensorData[3] = gSensorData.accel.x;
  rawSensorData[4] = gSensorData.accel.y;
  rawSensorData[5] = gSensorData.accel.z;

  KalmanFilter(state, rawSensorData);

  state_print(state);

  //delay(1000);

  //solenoid_close(SOLENOID1);
  //solenoid_close(SOLENOID2);

  //delay(1000);

}
