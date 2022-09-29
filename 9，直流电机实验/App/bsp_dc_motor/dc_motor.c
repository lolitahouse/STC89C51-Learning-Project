#include  "dc_motor.h"



/*
	函数名：DC_Motor_Run
	功能：	让直流电机运行 DC_MOTOR_RUN_TIME 时间
*/
void DC_Motor_Run(void)
{
	DC_Motor = 1;	//开启电机
	Delay_ms(DC_MOTOR_RUN_TIME);
	DC_Motor=0;		//关闭电机
}













