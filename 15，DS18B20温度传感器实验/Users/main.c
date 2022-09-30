/**************************************************************************************
实验名称：	DS18B20温度传感器实验
实验现象：	插上DS18B20温度传感器，数码管显示检测的温度值
实验单片机：普中A2			
注意事项：																		  
***************************************************************************************/

#include "public.h"
#include  "ds18b20.h"
#include  "smg.h"



int main(void)
{
	uint_8 i = 0;
   	int temper_value = 0;
	uint_8 temper_buf[5] = 0;

	DS18B20_Init();		//初始化DS18B20

	while(1)
	{				
		i++;
		if(i%50 == 0)		//间隔一段时间读取温度值，间隔时间要大于温度传感器转换温度时间
			temper_value = DS18B20_Read_Temperture()*10;	//保留温度值小数后一位
		if(temper_value < 0)	//负温度
		{
			temper_value = -temper_value;
			temper_buf[0] = 0x40;	//显示负号	
		}
		else
			temper_buf[0] = 0x00;	//不显示负号
		temper_buf[1] = gSmg_init_code[temper_value/1000];				//百位
		temper_buf[2] = gSmg_init_code[temper_value%1000/100];			//十位
		temper_buf[3] = gSmg_init_code[temper_value%1000%100/10]|0x80;	//个位+小数点
		temper_buf[4] = gSmg_init_code[temper_value%1000%100%10];			//小数点后一位
		Smg_Display(temper_buf,SHOW_POSITION);
	}
}




