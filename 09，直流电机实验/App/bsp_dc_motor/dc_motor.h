#ifndef __DC_MOTOR_H
#define __DC_MOTOR_H

#include  "public.h"

//定义直流电机控制管脚
sbit DC_Motor = P1^0;

//定义直流电机运行时间为3000ms
#define DC_MOTOR_RUN_TIME	3000

//函数声明
void DC_Motor_Run(void);	


#endif /*__DC_MOTOR_H*/