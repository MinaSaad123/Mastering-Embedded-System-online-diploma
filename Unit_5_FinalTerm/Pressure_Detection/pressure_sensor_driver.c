//include lib
#include "pressure_sensor_driver.h"

//datatype
int pressure_val = 0;

/*****************function defination*****************/
ST_define(init)
{
    P_ST_pressure_sensor_driver = ST(reading);

}

ST_define(reading)
{

	//get pressure from sensor
	pressure_val = get_pressure_val();
    //delay through going to waiting state
    ST_call(waiting);
    P_ST_pressure_sensor_driver = ST(reading);
}
ST_define(waiting)
{   
	int i;
    for(i = 5000; i != 0;--i);

}