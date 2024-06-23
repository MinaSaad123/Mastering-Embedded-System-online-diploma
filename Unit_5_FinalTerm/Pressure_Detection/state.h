//header protection
#ifndef STATE_H
#define STATE_H

//macros
#define ST_define(fun) void ST_##fun()
#define ST(fun) ST_##fun
#define ST_call(fun) ST_##fun()

//interfacing
int get_pressure_val();
void Delay(int nCount);
void set_alarm_actuator(int i);
void GPIO_initialize();
#endif