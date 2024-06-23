//include libs
#include <stdint.h>
#include "driver.h"
//include lib
#include "pressure_sensor_driver.h"
#include "alarm.h"


//some of datatypes
int thresold = 20;
extern int pressure_val;

/***************function prototype***************/
void setup()
{
    GPIO_initialize();
	P_ST_pressure_sensor_driver = ST(init);
	P_ST_pressure_sensor_driver();
	P_ST_alarm = ST(alarm_off);
	
}
int main ()
{   
	setup();
	//check pressure is more than thresold
	while (1)
	{
		P_ST_pressure_sensor_driver();
		if(pressure_val >= thresold)
		{
			P_ST_alarm = ST(alarm_on);
			P_ST_alarm();

		} 

	}
return 0;
}
