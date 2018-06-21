#include "SensorTask.h"

/* Assign a unique ID to the sensors */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_L3GD20_Unified  	    gyro	= Adafruit_L3GD20_Unified(30303); 
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
 * log new data in ggSensorData
 *
 */
void sensor_task(sensor_data_t *gSensorData){
	
	/* get accelerometer data */
	if(accel.getEvent(&accel_event)){
		gSensorData->accel.x = accel_event.acceleration.x;
		gSensorData->accel.y = accel_event.acceleration.y;
		gSensorData->accel.z = accel_event.acceleration.z;
	}
	
	/* get magnetometer data */
	if(mag.getEvent(&mag_event)){
		gSensorData->mag.x = mag_event.magnetic.x;
		gSensorData->mag.y = mag_event.magnetic.y;
		gSensorData->mag.z = mag_event.magnetic.z;
	}
	
	/* get gyroscope data */
	if(gyro.getEvent(&gyro_event)){
		gSensorData->gyro.x = gyro_event.gyro.x;
		gSensorData->gyro.y = gyro_event.gyro.y;
		gSensorData->gyro.z = gyro_event.gyro.z;
	}
	
	/* get barometer data */
	if(bmp.getEvent(&bmp_event)){
		gSensorData->bmp.temp = bmp_event.temperature;
		gSensorData->bmp.press = bmp_event.pressure;
	}
	
}

void sensor_print(sensor_data_t *gSensorData){

  Serial.print(millis());
  Serial.print(",");
  
  Serial.print(gSensorData->accel.x);
  Serial.print(",");
  Serial.print(gSensorData->accel.y);
  Serial.print(",");
  Serial.print(gSensorData->accel.z);
  
  Serial.print(",");
  Serial.print(gSensorData->gyro.x);
  Serial.print(",");
  Serial.print(gSensorData->gyro.y);
  Serial.print(",");
  Serial.print(gSensorData->gyro.z);
  Serial.print("\n");
   
}

void state_print(double x[12]){
  
  Serial.print(x[0]);
  Serial.print(",");
  Serial.print(x[1]);
  Serial.print(",");
  Serial.print(x[2]);
  
  Serial.print(",");
  Serial.print(x[3]);
  Serial.print(",");
  Serial.print(x[4]);
  Serial.print(",");
  Serial.print(x[5]);

  Serial.print(",");
  Serial.print(x[6]);
  Serial.print(",");
  Serial.print(x[7]);
  Serial.print(",");
  Serial.print(x[8]);

  Serial.print(",");
  Serial.print(x[9]);
  Serial.print(",");
  Serial.print(x[10]);
  Serial.print(",");
  Serial.print(x[11]);
  
  Serial.print("\n");
}

