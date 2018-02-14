#ifndef _SENSORTASK_H
#define _SENSORTASK_H

#ifdef _cplusplus
extern "C" {
#endif

#include <Wire.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "Adafruit_BMP085_U.h"
#include "Adafruit_L3GD20_U.h"
#include "Adafruit_10DOF.h"

/* accelerometer data struct */
typedef struct accel_data_s
{
	float x;
	float y;
	float z;
}accel_data_t;

/* magnetometer data struct */
typedef struct mag_data_s
{
	float x;
	float y;
	float z;
}mag_data_t;

/* gyroscope data struct */
typedef struct gyro_data_s
{
	float x;
	float y;
	float z;
}gyro_data_t;

/* barameter data struct */
typedef struct bmp_data_s
{
	float temp;
	float press;
}bmp_data_t;

/* sensor data struct */
typedef struct sensor_data_s
{
	accel_data_t accel;
	mag_data_t mag;
	gyro_data_t gyro;
	bmp_data_t bmp;
}sensor_data_t;

void sensor_init(void);
void sensor_task(sensor_data_t *gSensorData);

#ifdef _cplusplus
}
#endif

#endif