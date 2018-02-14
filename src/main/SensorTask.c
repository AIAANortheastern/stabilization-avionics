#include "SensorTask.h"
#include <Serial.h>

/* Assign a unique ID to the sensors */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_L3GD20_Unified  	  gyro	= Adafruit_L3GD20_Unified(30303); 
Adafruit_BMP085_Unified       bmp   = Adafruit_BMP085_Unified(18001);

sensors_event_t accel_event;
sensors_event_t mag_event;
sensors_event_t gyro_event;
sensors_event_t bmp_event;

/* 
 * initialize sensors
 * hang on error and display error message over serial
 *
 */
void sensor_init(void){
	
	/* open serial line at baud rate of 115200 */
	Serial.begin(115200);
	
	/* initialize accelerometer */
	if(!accel.begin()){
		Serial.println("accelerometer not detected");
		while(1);
	}
	
	/* initialize magnetometer */
	if(!mag.begin()){
		Serial.println("magnetometer not detected");
		while(1);
	}
	
	/* initialize gyroscope */
	if(!gyro.begin()){
		Serial.println("gyroscope not detected");
		while(1);
	}
	
	/* initialize barometer */
	if(!bmp.begin()){
		Serial.println("barometer not detected");
		while(1);
	}
	
}

/*
 * poll sensors for data
 * log new data in gSensorData
 *
 */
void sensor_task(sensor_data_t *gSensorData){
	
	/* get accelerometer data */
	if(accel.getEvent(&accel_event)){
		sensorData.accel.x = accel_event.x;
		sensorData.accel.y = accel_event.y;
		sensorData.accel.z = accel_event.z;
	}
	
	/* get magnetometer data */
	if(mag.getEvent(&mag_event)){
		sensorData.mag.x = mag_event.x;
		sensorData.mag.y = mag_event.y;
		sensorData.mag.z = mag_event.z;
	}
	
	/* get gyroscope data */
	if(gyro.getEvent(&gyro_event)){
		sensorData.gyro.x = gyro_event.x;
		sensorData.gyro.y = gyro_event.y;
		sensorData.gyro.z = gyro_event.z;
	}
	
	/* get barometer data */
	if(bmp.getEvent(&bmp_event)){
		sensorData.bmp.temp = bmp_event.temp;
		sensorData.bmp.press = bmp_event.press;
	}
	
}
