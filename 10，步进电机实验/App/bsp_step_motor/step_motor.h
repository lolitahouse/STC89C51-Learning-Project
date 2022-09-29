#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

#include  "public.h"

//定义ULN2003控制步进电机管脚
sbit IN1_A = P1^0;
sbit IN2_B = P1^1;
sbit IN3_C = P1^2;
sbit IN4_D = P1^3;

// 定义步进电机速度，值越小，速度越快
// 最小不能小于1
#define STEPMOTOR_MAXSPEED        1  
#define STEPMOTOR_MINSPEED        5 

//函数声明
void Step_Motor_Send_Pulse(uint_8 step,uint_8 dir);	


#endif /*__STEP_MOTOR_H*/