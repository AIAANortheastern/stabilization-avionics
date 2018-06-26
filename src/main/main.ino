#include "Solenoid.h"
#include "SensorTask.h"
//#include "KalmanFilter.h"
//#include "rt_nonfinite.h"
//#include "KalmanFilter_Initialize.h"

sensor_data_t gSensorData;

double rawSensorData[6];
//double state[12];
//double calibration[12];
//double output[12];

void setup() {
/*
  solenoid_init(SOLENOID1);
  solenoid_init(SOLENOID2);
  //KalmanFilter_initialize();

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

  calibration[0] = 0;
  calibration[1] = 0;
  calibration[2] = 0;
  calibration[3] = 0;
  calibration[4] = 0;
  calibration[5] = 0;
  calibration[6] = 0;
  calibration[7] = 0;
  calibration[8] = 0;
  calibration[9] = 0;
  calibration[10] = 0;
  calibration[11] = 0;
  

  delay(2000);
  */
  
  sensor_init();
/*
  delay(1000);

  for(int i = 0; i < 1000; i++){

    sensor_task(&gSensorData);
    
    rawSensorData[0] = gSensorData.gyro.x;
    rawSensorData[1] = gSensorData.gyro.y;
    rawSensorData[2] = gSensorData.gyro.z;
    rawSensorData[3] = gSensorData.accel.x;
    rawSensorData[4] = gSensorData.accel.y;
    rawSensorData[5] = gSensorData.accel.z;
  
    KalmanFilter(state, rawSensorData);

    if(i >= 990){
      calibration[0] += state[0];
      calibration[1] += state[1];
      calibration[2] += state[2];
      calibration[3] += state[3];
      calibration[4] += state[4];
      calibration[5] += state[5];
      calibration[6] += state[6];
      calibration[7] += state[7];
      calibration[8] += state[8];
      calibration[9] += state[9];
      calibration[10] += state[10];
      calibration[11] += state[11];
    }
    
  }

  calibration[0] = calibration[0]/10;
  calibration[1] = calibration[1]/10;
  calibration[2] = calibration[2]/10;
  calibration[3] = calibration[3]/10;
  calibration[4] = calibration[4]/10;
  calibration[5] = calibration[5]/10;
  calibration[6] = calibration[6]/10;
  calibration[7] = calibration[7]/10;
  calibration[8] = calibration[8]/10;
  calibration[9] = calibration[9]/10;
  calibration[10] = calibration[10]/10;
  calibration[11] = calibration[11]/10 - 9.81;
*/
}

void loop() {

  sensor_task(&gSensorData);
/*
  rawSensorData[0] = gSensorData.gyro.x;
  rawSensorData[1] = gSensorData.gyro.y;
  rawSensorData[2] = gSensorData.gyro.z;
  rawSensorData[3] = gSensorData.accel.x;
  rawSensorData[4] = gSensorData.accel.y;
  rawSensorData[5] = gSensorData.accel.z;

  KalmanFilter(state, rawSensorData);

  output[0] = state[0] - calibration[0];
  output[1] = state[1] - calibration[1];
  output[2] = state[2] - calibration[2];
  output[3] = state[3] - calibration[3];
  output[4] = state[4] - calibration[4];
  output[5] = state[5] - calibration[5];
  output[6] = state[6] - calibration[6];
  output[7] = state[7] - calibration[7];
  output[8] = state[8] - calibration[8];
  output[9] = state[9] - calibration[9];
  output[10] = state[10] - calibration[10];
  output[11] = state[11] - calibration[11];
*/
  //state_print(output);
  log_raw(&gSensorData);
}
