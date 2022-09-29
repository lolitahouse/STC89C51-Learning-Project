#include  "step_motor.h"

/*
	��������Step_Motor_Send_Pulse
	���ܣ�	���һ�����ݸ�ULN2003���Ӷ�ʵ���򲽽��������һ������
	������	step�� ָ��������ţ���ѡֵ0~7
			dir��  ����ѡ��, 1��˳ʱ��,0����ʱ��	
*/
void Step_Motor_Send_Pulse(uint_8 step,uint_8 dir)
{
	uint_8 temp = step;
	
	if(dir == 0)			//���Ϊ��ʱ����ת
		temp = 7-step;		//���������ź�
	switch(temp)//8�����Ŀ��ƣ�A->AB->B->BC->C->CD->D->DA
	{
		case 0: IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=0; break;
		case 1: IN1_A=1;IN2_B=1;IN3_C=0;IN4_D=0; break;
		case 2: IN1_A=0;IN2_B=1;IN3_C=0;IN4_D=0; break;
		case 3: IN1_A=0;IN2_B=1;IN3_C=1;IN4_D=0; break;
		case 4: IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=0; break;
		case 5: IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=1; break;
		case 6: IN1_A=0;IN2_B=0;IN3_C=0;IN4_D=1; break;
		case 7: IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=1; break;
		default: IN1_A=0;IN2_B=0;IN3_C=0;IN4_D=0; break;//ֹͣ����	
	}			
}













