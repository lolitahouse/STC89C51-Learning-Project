/**************************************************************************************
实验名称：	红外遥控实验
实验现象：	数码管上显示数码管上显示红外解码遥控器键值
实验单片机：普中A2			
注意事项：																		  
***************************************************************************************/

#include "public.h"
#include  "ired.h"
#include  "smg.h"



int main(void)
{
	uint_8 ired_buf[3] = 0;

	Ired_Init();	//红外初始化

	while(1)
	{	
	   	ired_buf[0] = gSmg_init_code[gired_data[2]/16];	//将控制码高4位转换为数码管段码
		ired_buf[1] = gSmg_init_code[gired_data[2]%16];	//将控制码低4位转换为数码管段码
		ired_buf[2] = 0X76;								//显示H的段码

		Smg_Display(ired_buf,SHOW_POSITION);	
	}
}




