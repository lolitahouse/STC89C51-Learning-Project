/**************************************************************************************
ʵ�����ƣ�	�������ʵ��
ʵ������	����KEY1���ɵ��ڵ����ת���򣻰���KEY2����������٣�����KEY3�����������;
ʵ�鵥Ƭ��������A2			
ע�����	�����������ɫ�߶Խӵ����������ģ�顱�������J47��5V�ϣ������������ν���																	  
***************************************************************************************/

#include "public.h"
#include  "step_motor.h"
#include  "key.h"

int main(void)
{
	uint_8 key_value = 0;
	uint_8 dir = 0;   //Ĭ����ʱ�뷽��
	uint_8 speed = STEPMOTOR_MAXSPEED;	//Ĭ������ٶ���ת
	uint_8 step = 0;
					
	while(1)
	{
		key_value = Key_Scan(0);			//����ɨ��
		if(key_value == KEY1_PRESS)			//key1 ����
		{
			dir = !dir;    
		}
		else if(key_value == KEY2_PRESS)	//key2 ����
		{
			if(speed > STEPMOTOR_MAXSPEED)
				speed -= 1;			
		}
		else if(key_value == KEY3_PRESS)	//key3 ����
		{
			if(speed < STEPMOTOR_MINSPEED)
				speed += 1;			
		}	

		Step_Motor_Send_Pulse(step++,dir);
		if(step == 8)		step = 0;		
		Delay_ms(speed);
	}
}