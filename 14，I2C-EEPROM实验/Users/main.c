/**************************************************************************************
实验名称：	I2C-EEPROM实验
实验现象：	数码管右4位显示0，按K1键将数据写入到EEPROM内保存，
		  	按K2键读取EEPROM内保存的数据，按K3键显示数据加1，按K4键显示数据清零，
		  	最大能写入的数据是255。
实验单片机：普中A2			
注意事项：																		  
***************************************************************************************/

#include "public.h"
#include  "24c02.h"
#include  "key.h"
#include  "smg.h"



int main(void)
{
	uint_8 key_value = 0;
   	uint_8 save_value = 0;
	uint_8 save_buf[3];
					
	while(1)
	{
		key_value = Key_Scan(KEY_SCAN_MODE);  	//单次扫描
		if(key_value == KEY1_PRESS)
		{
			AT24C02_Write_One_Byte(EEPROM_ADDRESS,save_value);	 //key1,写入
		}
		else if(key_value == KEY2_PRESS)
		{
			save_value = AT24C02_Read_One_Byte(EEPROM_ADDRESS);	 //key2，读取
		}
		else if(key_value == KEY3_PRESS)
		{
			save_value++;								//key3，加1
			if(save_value == 255)
				save_value = 255;
		}
		else if(key_value == KEY4_PRESS)
		{
			save_value = 0;							 	//key4，清零
		}
		save_buf[0]=save_value/100;
		save_buf[1]=save_value%100/10;
		save_buf[2]=save_value%100%10;
		Smg_Display(save_buf,SHOW_POSITION);	     //数码管显示
	}
}




