//header protection
#ifndef ALARM_H
#define ALARM_H

//include lib
#include "state.h"

//pointer to fun
void (*P_ST_alarm)();

/***************function prototype***************/
ST_define(alarm_off);
ST_define(alarm_on);
ST_define(init);
#endif
