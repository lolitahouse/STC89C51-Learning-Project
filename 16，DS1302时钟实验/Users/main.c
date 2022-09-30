/**************************************************************************************
实验名称：	DS1302时钟实验
实验现象：	数码管上显示电子时钟时分秒，格式为“XX-XX-XX”
实验单片机：普中A2			
注意事项：																		  
***************************************************************************************/

#include "public.h"
#include  "ds1302.h"
#include  "smg.h"



int main(void)
{
	uint_8 time_buf[8];
	
	DS1302_Init();		//初始化DS1302

	while(1)
	{	
	   	DS1302_Read_Time();

		time_buf[0] = gSmg_init_code[gDS1302_TIME[2]/16];		//时
		time_buf[1] = gSmg_init_code[gDS1302_TIME[2]&0x0f];
		time_buf[2] = 0x40;
		time_buf[3] = gSmg_init_code[gDS1302_TIME[1]/16];		//分
		time_buf[4] = gSmg_init_code[gDS1302_TIME[1]&0x0f];
		time_buf[5] = 0x40;
		time_buf[6] = gSmg_init_code[gDS1302_TIME[0]/16];		//秒
		time_buf[7] = gSmg_init_code[gDS1302_TIME[0]&0x0f];

		Smg_Display(time_buf,SHOW_POSITION);
	}
}




