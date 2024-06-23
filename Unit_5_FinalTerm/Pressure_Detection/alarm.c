//include lib
#include "alarm.h"

//datatype
static int count = 250000;

/*****************function defination*****************/
ST_define(alarm_off)
{
    //make alarm off through API
	set_alarm_actuator(1);
    P_ST_alarm = ST(alarm_off);	


}
ST_define(alarm_on)
{
	//make alarm on through API
	set_alarm_actuator(0);

	//timer for alarm
	//timer begin
	Delay(count);
	//timer end

	//make alarm is off
	set_alarm_actuator(1);
    P_ST_alarm = ST(alarm_off);	



}
