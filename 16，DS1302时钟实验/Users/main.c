/**************************************************************************************
ʵ�����ƣ�	DS1302ʱ��ʵ��
ʵ������	���������ʾ����ʱ��ʱ���룬��ʽΪ��XX-XX-XX��
ʵ�鵥Ƭ��������A2			
ע�����																		  
***************************************************************************************/

#include "public.h"
#include  "ds1302.h"
#include  "smg.h"



int main(void)
{
	uint_8 time_buf[8];
	
	DS1302_Init();		//��ʼ��DS1302

	while(1)
	{	
	   	DS1302_Read_Time();

		time_buf[0] = gSmg_init_code[gDS1302_TIME[2]/16];		//ʱ
		time_buf[1] = gSmg_init_code[gDS1302_TIME[2]&0x0f];
		time_buf[2] = 0x40;
		time_buf[3] = gSmg_init_code[gDS1302_TIME[1]/16];		//��
		time_buf[4] = gSmg_init_code[gDS1302_TIME[1]&0x0f];
		time_buf[5] = 0x40;
		time_buf[6] = gSmg_init_code[gDS1302_TIME[0]/16];		//��
		time_buf[7] = gSmg_init_code[gDS1302_TIME[0]&0x0f];

		Smg_Display(time_buf,SHOW_POSITION);
	}
}




