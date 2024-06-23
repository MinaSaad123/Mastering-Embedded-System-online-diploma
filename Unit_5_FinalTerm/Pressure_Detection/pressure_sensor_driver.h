//header protection
#ifndef PRESSURE_SENSOR_DRIVER_H
#define PRESSURE_SENSOR_DRIVER_H

//include lib
#include "state.h"

//pointer to fun
void (*P_ST_pressure_sensor_driver)();

/***************function prototype***************/
ST_define(reading);
ST_define(waiting);
ST_define(init);
#endif
