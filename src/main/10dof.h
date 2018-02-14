
#ifndef _10DOF_H
#define _10DOF_H

#include <Wire.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "Adafruit_BMP085_U.h"
#include "Adafruit_L3GD20_U.h"
#include "Adafruit_10DOF.h"

void init_sensors(void);
void init(void);
void sensor_print_data(void);

#endif
