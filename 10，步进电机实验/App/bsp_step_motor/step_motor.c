#include  "step_motor.h"

/*
	函数名：Step_Motor_Send_Pulse
	功能：	输出一个数据给ULN2003，从而实现向步进电机发送一个脉冲
	参数：	step： 指定步进序号，可选值0~7
			dir：  方向选择, 1：顺时针,0：逆时针	
*/
void Step_Motor_Send_Pulse(uint_8 step,uint_8 dir)
{
	uint_8 temp = step;
	
	if(dir == 0)			//如果为逆时针旋转
		temp = 7-step;		//调换节拍信号
	switch(temp)//8个节拍控制：A->AB->B->BC->C->CD->D->DA
	{
		case 0: IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=0; break;
		case 1: IN1_A=1;IN2_B=1;IN3_C=0;IN4_D=0; break;
		case 2: IN1_A=0;IN2_B=1;IN3_C=0;IN4_D=0; break;
		case 3: IN1_A=0;IN2_B=1;IN3_C=1;IN4_D=0; break;
		case 4: IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=0; break;
		case 5: IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=1; break;
		case 6: IN1_A=0;IN2_B=0;IN3_C=0;IN4_D=1; break;
		case 7: IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=1; break;
		default: IN1_A=0;IN2_B=0;IN3_C=0;IN4_D=0; break;//停止相序	
	}			
}













