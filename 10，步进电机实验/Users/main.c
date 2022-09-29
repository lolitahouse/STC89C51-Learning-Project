/**************************************************************************************
实验名称：	步进电机实验
实验现象：	按下KEY1键可调节电机旋转方向；按下KEY2键，电机加速；按下KEY3键，电机减速;
实验单片机：普中A2			
注意事项：	将步进电机红色线对接到“步进电机模块”输出端子J47的5V上，其它相序依次接入																	  
***************************************************************************************/

#include "public.h"
#include  "step_motor.h"
#include  "key.h"

int main(void)
{
	uint_8 key_value = 0;
	uint_8 dir = 0;   //默认逆时针方向
	uint_8 speed = STEPMOTOR_MAXSPEED;	//默认最大速度旋转
	uint_8 step = 0;
					
	while(1)
	{
		key_value = Key_Scan(0);			//单次扫描
		if(key_value == KEY1_PRESS)			//key1 换向
		{
			dir = !dir;    
		}
		else if(key_value == KEY2_PRESS)	//key2 加速
		{
			if(speed > STEPMOTOR_MAXSPEED)
				speed -= 1;			
		}
		else if(key_value == KEY3_PRESS)	//key3 减速
		{
			if(speed < STEPMOTOR_MINSPEED)
				speed += 1;			
		}	

		Step_Motor_Send_Pulse(step++,dir);
		if(step == 8)		step = 0;		
		Delay_ms(speed);
	}
}