#include  "dc_motor.h"



/*
	��������DC_Motor_Run
	���ܣ�	��ֱ��������� DC_MOTOR_RUN_TIME ʱ��
*/
void DC_Motor_Run(void)
{
	DC_Motor = 1;	//�������
	Delay_ms(DC_MOTOR_RUN_TIME);
	DC_Motor=0;		//�رյ��
}













